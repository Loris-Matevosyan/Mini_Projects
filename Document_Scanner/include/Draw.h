#ifndef _DRAW_
#define _DRAW_

#include <opencv2/imgproc.hpp>


using vecOfPoint = std::vector<cv::Point>;



void draw(cv::Mat& image, const vecOfPoint& points, const cv::Scalar& color)
{
	for (int i = 0; i < points.size(); ++i)
	{
		cv::circle(image, points[i], 10, color, cv::FILLED);
		cv::putText(image, std::to_string(i), points[i], cv::FONT_HERSHEY_PLAIN, 4, color, 4);
	}
}



#endif //_DRAW_