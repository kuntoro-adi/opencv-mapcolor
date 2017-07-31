#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>

#include "MapIntensity.h"

using namespace cv;
using namespace std;

void display(String title, InputArray img) {
	namedWindow(title, WINDOW_AUTOSIZE);
	imshow(title, img);
}

void halt() {
	waitKey(0);
	destroyAllWindows();
}


int main(int argc, char** argv) {

	/// Photo from 
	/// https://www.pexels.com/photo/animal-kitten-cat-pet-7517/
	/// load image
	Mat img = imread("animal-sitting-animals-inside.jpg", IMREAD_COLOR);

	if (img.empty())
	{
		cout << "Can not load image" << endl;
	}
	resize(img, img, Size(640, 480));

	/// Grayscale intensity mapping

	Mat srcGray; 
	Mat dstGray;
	cvtColor(img, srcGray, COLOR_BGR2GRAY);

	mapIntensity(srcGray, dstGray, Range(0, 255), Range(255, 0));
	
	display("Mapped - Grayscale", dstGray);
	
	/// HSV intensity mapping

	/// hsv initial range
	vector<Range> initial;
	initial.push_back(Range(80, 120)); // hue
	initial.push_back(Range(0, 255)); // saturation
	initial.push_back(Range(0, 255)); // value
	/// hsv target range
	vector<Range> target;
	target.push_back(Range(35, 70)); // hue
	target.push_back(Range(0, 255)); // saturation
	target.push_back(Range(0, 255)); // value

	Mat hsvMapped;
	cvtColor(img, hsvMapped, COLOR_BGR2HSV);
	mapIntensity(hsvMapped, hsvMapped, initial, target);
	cvtColor(hsvMapped, hsvMapped, COLOR_HSV2BGR);

	display("Mapped - Color", hsvMapped);

	/// The original image
	display("Color Image", img);
	display("Grayscale Image", srcGray);

	halt();

	return 0;
}