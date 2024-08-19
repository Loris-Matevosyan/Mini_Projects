#ifndef _REORDERPOINTS_
#define _REORDERPOINTS_

#include <opencv2/imgproc.hpp>
#include <algorithm>
#include <vector>


using vecOfPoint = std::vector<cv::Point>;


vecOfPoint reorderPoints(const vecOfPoint& points) 
{
	vecOfPoint newPoints;
	std::vector<int> sumPoints, subPoints;

	for (int i = 0; i < 4; ++i)
	{
		sumPoints.push_back(points[i].x + points[i].y);
		subPoints.push_back(points[i].x - points[i].y);
	}

	newPoints.push_back(points[std::min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]);
	newPoints.push_back(points[std::max_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]);
	newPoints.push_back(points[std::min_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]);
	newPoints.push_back(points[std::max_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]);
	
	/*   Understandable way to write it
 
	int sumMinIndex, sumMaxIndex, subMinIndex, subMaxIndex;

	sumMinIndex = std::min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin();    // Upper left corner
	subMaxIndex = std::max_element(subPoints.begin(), subPoints.end()) - subPoints.begin();    // Upper right corner
	subMinIndex = std::min_element(subPoints.begin(), subPoints.end()) - subPoints.begin();    // Buttom left corner
	sumMaxIndex = std::max_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin();    // Buttom right corner

	newPoints.push_back(points[sumMinIndex]);  // 0
	newPoints.push_back(points[subMaxIndex]);  // 1
	newPoints.push_back(points[subMinIndex]);  // 2
	newPoints.push_back(points[sumMaxIndex]);  // 3

	*/

	return newPoints;
}



#endif //_REORDERPOINTS_
