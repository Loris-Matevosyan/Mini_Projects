#include <opencv2/highgui.hpp>
#include "include/Log.h"
#include "include/FindPoints.h"
#include "include/Draw.h"


using vecOfvecOfint = std::vector<std::vector<int>>;
using vecOfScalar = std::vector<cv::Scalar>;



int main()
{
	voidLog();

	vecOfvecOfint detectColors{
		{138,118,171,179,255,255},	//Red
		{110,124,0,140,255,255}		//Blue
	};

	vecOfScalar drawColors{
		{0,0,255},	 //Red
		{255,0,0}	 //Blue
	};

	vecOfvecOfint points;

	cv::VideoCapture capture(0);
	cv::Mat image;


	while (true)
	{
		capture.read(image);
		
		findPoints(image, detectColors, points);
		draw(points, drawColors, image);

		cv::imshow("Image", image);
		cv::waitKey(1);
	}


	return 0;

}