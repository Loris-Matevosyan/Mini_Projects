#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <vector>
#include <string>
#include "Log.h"


using vecOfRect = std::vector<cv::Rect>;


int main()
{

	voidLog();

	cv::VideoCapture cap(0);
	cv::Mat image;
	vecOfRect plates;

	cv::CascadeClassifier plateCascade;
	plateCascade.load("Resources/haarcascade_russian_plate_number.xml");

	if (plateCascade.empty())
	{
		std::cout << "XML file not loaded" << std::endl;
	}

	while (true)
	{
		cap.read(image);

		plateCascade.detectMultiScale(image, plates, 1.1, 10);

		for (int i = 0; i < plates.size(); ++i)
		{
			cv::Mat imageCrop = image(plates[i]);
			cv::imwrite("Resources/Plates/" + std::to_string(i) + ".png", imageCrop);

			cv::rectangle(image, plates[i].tl(), plates[i].br(), cv::Scalar(255, 0, 255), 3);
		}

		cv::imshow("Detector", image);
		cv::waitKey(1);
	}

	return 0;

}