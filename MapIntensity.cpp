#include "MapIntensity.h"

/// Function to map between two ranges of intensity.  The initial intensity will be mapped
/// to the target intensity. This function assumes that the input only has one channel.
void mapIntensity(InputArray src, OutputArray dst, Range initialIntensity, Range targetIntensity)
{
	if (src.getMat().channels() > 1) {
		throw invalid_argument("number of channel > 1");
		return;
	}

	/// Convert Mat to float to enable floating point and negative value
	Mat srcMat;
	src.getMat().convertTo(srcMat, CV_32F);
	/// Specify the region which satisfies the initial intensity criteria
	Mat region;
	inRange(srcMat, initialIntensity.start, initialIntensity.end, region);

	/// Compute the mapped intensity given the region of interest
	Mat resultTemp(srcMat.rows, srcMat.cols, srcMat.type());
	subtract(srcMat, (float)initialIntensity.start, resultTemp, region);
	divide(resultTemp, (float)(initialIntensity.end - initialIntensity.start), resultTemp);
	multiply(resultTemp, (float)(targetIntensity.end - targetIntensity.start), resultTemp);
	add(resultTemp, targetIntensity.start, resultTemp, region);

	/// Convert to the default format back to enable displaying
	resultTemp.convertTo(resultTemp, CV_8U);

	/// Now add the non-region of interest with the region with mapped intensity 
	Mat inverseRegion;
	bitwise_not(region, inverseRegion);
	Mat excluded;
	srcMat.copyTo(excluded, inverseRegion);
	excluded.convertTo(excluded, CV_8U);

	Mat result;
	add(excluded, resultTemp, result);

	/// Set the output value
	dst.assign(result);
}

/// Function to map between two ranges of intensities. 
/// This function can handle multichannel.
void mapIntensity(InputArray src, OutputArray dst, vector<Range> initialIntensities, vector<Range> targetIntensities)
{
	Mat srcMat = src.getMat();
	
	/// Check if the number of intensities to be mapped conforms the number of image channels
	if ((initialIntensities.size() != srcMat.channels()) && (targetIntensities.size() != srcMat.channels())) {
		throw invalid_argument("the number of channel doesn't match the number intensity range");
		return;
	}
	
	/// Split each channel
	vector<Mat> channels;
	split(srcMat, channels);

	/// Map each channel
	for (int i = 0; i < channels.size(); i++) {
		mapIntensity(channels[i], channels[i], 
			Range(initialIntensities[i].start, initialIntensities[i].end), 
			Range(targetIntensities[i].start, targetIntensities[i].end));
	}

	/// Combine back
	Mat result;
	merge(channels, result);

	/// Set the output value
	dst.assign(result);
}
