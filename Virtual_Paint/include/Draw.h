#ifndef _DRAW_
#define _DRAW_

#include <opencv2/imgproc.hpp>
#include <vector>


using vecOfvecOfint = std::vector<std::vector<int>>;



inline void draw(const vecOfvecOfint& points, const std::vector<cv::Scalar>& drawColors, cv::Mat& img)
{
	for (int i = 0; i < points.size(); ++i)
	{
		cv::circle(img, cv::Point(points[i][0], points[i][1]), 10, drawColors[points[i][2]], cv::FILLED);
	}
}



#endif // _DRAW_
