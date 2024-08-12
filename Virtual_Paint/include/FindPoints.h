#ifndef _FINDPOINTS_
#define _FINDPOINTS_

#include <opencv2/imgproc.hpp>
#include <vector>


using vecOfvecOfpoint = std::vector<std::vector<cv::Point>>;
using vecOfvecOfint = std::vector<std::vector<int>>;
using vecOfint = std::vector<int>;
using vecOfVec4i = std::vector<cv::Vec4i>;
using vecOfRect = std::vector<cv::Rect>;



inline cv::Mat createInRangeImage(const vecOfint& detectColor, const cv::Mat& imageHSV);
inline cv::Point findContour(const cv::Mat& image, const cv::Mat& mask);


inline void findPoints(cv::Mat& image, const vecOfvecOfint& detectColors, vecOfvecOfint& points)
{
	cv::Mat imageHSV, mask;
	cv::Point point;

	cv::cvtColor(image, imageHSV, cv::COLOR_BGR2HSV);

	for (int i = 0; i < detectColors.size(); ++i)
	{
		mask = createInRangeImage(detectColors[i], imageHSV);

		//Output
		//cv::imshow(std::to_string(i), mask);

		point = findContour(image, mask);

		if (point.x != 0 && point.y != 0)
		{
			points.push_back({ point.x, point.y, i });
		}
	} 
}


inline cv::Mat createInRangeImage(const vecOfint& detectColor, const cv::Mat& imageHSV)
{
	cv::Scalar lower(detectColor[0], detectColor[1], detectColor[2]);
	cv::Scalar upper(detectColor[3], detectColor[4], detectColor[5]);

	cv::Mat mask;
	cv::inRange(imageHSV, lower, upper, mask);

	return mask;
}


inline cv::Point findContour(const cv::Mat& image, const cv::Mat& mask)
{
	vecOfvecOfpoint contours;
	vecOfVec4i hierarchy;

	cv::findContours(mask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	vecOfvecOfpoint conPoly(contours.size());
	vecOfRect boundRect(contours.size());

	cv::Point myPoint(0, 0);

	for (int i = 0; i < contours.size(); ++i)
	{
		int area = cv::contourArea(contours[i]);

		if (area > 1000)
		{
			float peri = cv::arcLength(contours[i], true);
			cv::approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			boundRect[i] = boundingRect(conPoly[i]);

			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			myPoint.y = boundRect[i].y;

			//Output
			//cv::drawContours(image, conPoly, i, cv::Scalar(255, 0, 255), 2); 
			//cv::rectangle(image, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(0, 255, 0), 5);
		}

	}

	return myPoint;
}



#endif // _FINDPOINTS_
