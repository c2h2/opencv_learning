#include <highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>
#include <stdio.h> 
#include <iostream> 

#define IMGFORMAT	".jpg"
#define BASENAME	"c2h2cap_"
#define WINDOW_NAME	"c2h2webcam"
#define WINDOW_NAME2	"c2h2processed"

int main() {
  	int i=0; //number of frames
  	char str[64];
  	char buf[5];
 
	cv::Mat frame;
	cv::Mat matProcessed;
	cv::VideoCapture capWebcam;

	std::vector<cv::Vec3f> vecCircles;
	std::vector<cv::Vec3f>::iterator itrCircles;

	if(!capWebcam.open(0)){
		printf("unable to open camera stream");
	}

	cv::namedWindow(WINDOW_NAME, cv::WINDOW_AUTOSIZE);
	cv::namedWindow(WINDOW_NAME2, cv::WINDOW_AUTOSIZE);
	// not effective
	cv::resizeWindow(WINDOW_NAME, 480, 320);
	cv::resizeWindow(WINDOW_NAME2, 480, 320);

	while(true){
		
		capWebcam.read(frame);
		cv::resize(frame, frame, cv::Size(640, 360), 0, 0, cv::INTER_CUBIC);
		cv::inRange(frame, cv::Scalar(100,0,0), cv::Scalar(255,100,100), matProcessed);  //scalar is BRG not RGB
		cv::GaussianBlur(matProcessed, matProcessed, cv::Size(9,9), 1.5);
		//cv::HoughCircles(matProcessed, vecCircles, CV_HOUGH_GRADIENT, 2, matProcessed.rows / 4, 100, 50, 10, 400);

		//for(itrCircles = vecCircles.begin(); itrCircles != vecCircles.end(); itrCircles++){
		//	std::cout <<"x="<<  itrCircles[0] << "\n"; // << ", y=" <<  itrCircles[1] << ", z=" <<itrCircles[2] << "\n";
		//}

		imshow(WINDOW_NAME, frame);
		imshow(WINDOW_NAME2, matProcessed);
		strcpy(str, BASENAME);
		sprintf(buf,"%05d",i);
		strcat(str, buf);
		strcat(str, IMGFORMAT);

		//imwrite(str , frame);
		//i++;
	}
	return 0;
}
