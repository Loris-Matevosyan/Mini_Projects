#ifndef _GETCONTOUR_
#define _GETCONTOUR_

#include <opencv2/imgproc.hpp>
#include <vector>


using vecOfvecOfPoint = std::vector<std::vector<cv::Point>>;
using vecOfPoint = std::vector<cv::Point>;
using vecOfVec4i = std::vector<cv::Vec4i>;
using vecOfRect = std::vector<cv::Rect>;



vecOfPoint getContour(const cv::Mat& image)
{
	vecOfvecOfPoint contours;
	vecOfVec4i hierarchy;

	cv::findContours(image, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	vecOfvecOfPoint conPoly(contours.size());
	vecOfRect boundRect(contours.size());
	vecOfPoint biggestContour;
	int area{}, maxArea{0};

	for (int i = 0; i < contours.size(); ++i)
	{
		area = cv::contourArea(contours[i]);

		if (area > 1000)
		{
			float peri = cv::arcLength(contours[i], true);
			cv::approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			if (area > maxArea && conPoly[i].size() == 4)
			{
				biggestContour = { conPoly[i][0], conPoly[i][1], conPoly[i][2], conPoly[i][3] };
				maxArea = area;
			}
		}
	}

	return biggestContour;
}




#endif //_GETCONTOUR_
