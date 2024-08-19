#ifndef _GETWARP_
#define _GETWARP_

#include <opencv2/imgproc.hpp>
#include <vector>


using vecOfPoint = std::vector<cv::Point>;


cv::Mat getWarp(const cv::Mat& image, const vecOfPoint& points, const float& width, const float& height)
{
	cv::Point2f src[4] = { points[0], points[1], points[2], points[3] };
	cv::Point2f dst[4] = { {0.0f, 0.0f}, {width, 0.0f}, {0.0f, height}, {width, height} };

	cv::Mat imageWarp;
	cv::Mat matrix = cv::getPerspectiveTransform(src, dst);
	cv::warpPerspective(image, imageWarp, matrix, cv::Point(width, height));

	return imageWarp;
}



#endif //_GETWARP_