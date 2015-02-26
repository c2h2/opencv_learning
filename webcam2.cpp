#include <highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>
#include <stdio.h>  

#define IMGFORMAT	".jpg"
#define BASENAME	"c2h2cap_"
#define WINDOW_NAME	"c2h2webcam"

int main() {
  	int i=0; //number of frames
  	char str[64];
  	char buf[5];
 
	cv::Mat frame;
	cv::VideoCapture capWebcam;

	if(!capWebcam.open(0)){
		printf("unable to open camera stream");
	}

	cv::namedWindow(WINDOW_NAME, cv::WINDOW_AUTOSIZE);

	while(true){
		
		capWebcam.read(frame);
		imshow(WINDOW_NAME, frame);
		strcpy(str, BASENAME);
		sprintf(buf,"%05d",i);
		strcat(str, buf);
		strcat(str, IMGFORMAT);

		//imwrite(str , frame);
		//i++;
	}
	return 0;
}
