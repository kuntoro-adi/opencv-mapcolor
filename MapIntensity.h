#pragma once

#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

void mapIntensity(InputArray src, OutputArray dst, Range initialIntensity, Range targetIntensity);

void mapIntensity(InputArray src, OutputArray dst, vector<Range> initialIntensities, vector<Range> targetIntensities);