#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>



int main()
{
	cv::VideoCapture cap(0);
	cv::Mat image, imageHSV, mask;

	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 179, smax = 255, vmax = 255;
	
	cv::namedWindow("Trackbars", (640, 200));
	cv::createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	cv::createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	cv::createTrackbar("Sat Min", "Trackbars", &smin, 255);
	cv::createTrackbar("Sat Max", "Trackbars", &smax, 255);
	cv::createTrackbar("Val Min", "Trackbars", &vmin, 255);
	cv::createTrackbar("Val Max", "Trackbars", &vmax, 255);


	while (true)
	{
		cap.read(image);

		cv::cvtColor(image, imageHSV, cv::COLOR_BGR2HSV);
		
		cv::Scalar lower(hmin, smin, vmin);
		cv::Scalar upper(hmax, smax, vmax);

		cv::inRange(imageHSV, lower, upper, mask);

		std::cout << hmin << "," << smin << "," << vmin << "," << hmax << "," << smax << "," << vmax << std::endl;

		cv::imshow("Image", image);
		cv::imshow("Mask", mask);

		cv::waitKey(1);
	}

	return 0;
}