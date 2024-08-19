#ifndef _PREPROCESSIMAGE_
#define _PREPROCESSIMAGE_
 
#include <opencv2/imgproc.hpp>



cv::Mat preProcessingImage(const cv::Mat& image)
{
	cv::Mat imageGray, imageBlur, imageCanny, imageDil;

	cv::cvtColor(image, imageGray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(imageGray, imageBlur, cv::Size(3, 3), 3, 0);
	cv::Canny(imageBlur, imageCanny, 25, 75);

	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate(imageCanny, imageDil, kernel);

	return imageDil;
}




#endif //_PREPROCESSIMAGE_
