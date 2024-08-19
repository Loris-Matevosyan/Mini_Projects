#include <opencv2/highgui.hpp>
#include <string>
#include "Log.h"
#include "Draw.h"
#include "PreProcessImage.h"
#include "GetContour.h"
#include "ReorderPoints.h"
#include "GetWarp.h"


using vecOfPoint = std::vector<cv::Point>;



int main()
{
	voidLog();

	cv::Mat imageOriginal, imageThreshold, imageWarp, imageCrop;
	vecOfPoint initialPoints, finalPoints;
	float paperWidth = 420, paperHeight = 596;
	int cropPixels = 5;

	std::string path = "Resources/paper.jpg";
	imageOriginal = cv::imread(path);
	//cv::resize(imageOriginal, imageOriginal, cv::Size(), 0.5, 0.5);

	imageThreshold = preProcessingImage(imageOriginal);
	initialPoints = getContour(imageThreshold);
	finalPoints = reorderPoints(initialPoints); 
	imageWarp = getWarp(imageOriginal, finalPoints, paperWidth, paperHeight);

	//draw(imageOriginal, initialPoints, cv::Scalar(0, 0, 255));
	//draw(imageOriginal, finalPoints, cv::Scalar(0, 255, 0));

	cv::Rect roi(cropPixels, cropPixels, paperWidth - (cropPixels * 5), paperHeight - (cropPixels * 5));
	// region of interest
	imageCrop = imageWarp(roi);

	cv::imshow("Image", imageOriginal);
	//cv::imshow("Image Dilation", imageThreshold);
	//cv::imshow("Image Warp", imageWarp);
	cv::imshow("Image Crop", imageCrop);
	cv::waitKey(0);


	return 0;
}