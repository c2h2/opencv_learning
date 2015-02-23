#include "highgui.h"
#include <stdio.h>
#include <stdlib.h>
#include <cv.h>
#include <stdio.h>  

#define IMGFORMAT	".jpg"
#define BASENAME	"c2h2cap_"
#define WINDOW_NAME	"c2h2webcam"

int main() {
	CvCapture* capture = cvCaptureFromCAM( CV_CAP_ANY );
	if ( !capture ) {
		fprintf( stderr, "ERROR: capture is NULL \n" );
		getchar();
		return -1;
 	}
 
	// Create a window in which the captured images will be presented
 	cvNamedWindow( WINDOW_NAME, CV_WINDOW_AUTOSIZE );
 	// Show the image captured from the camera in the window and repeat
  	int i=0; //number of frames
  	char str[64];
  	char buf[5];

	while ( 1 ) {
		IplImage* frame = cvQueryFrame( capture );
		if ( !frame ) {
			fprintf( stderr, "ERROR: null frame...\n" );
			getchar();
			break;
	 	}

		cvShowImage(WINDOW_NAME, frame );
		strcpy(str, BASENAME);
		sprintf(buf,"%05d",i);
		strcat(str, buf);
		strcat(str, IMGFORMAT);
		cvSaveImage(str, frame);
   		i++;

		if ( (cvWaitKey(10) & 255) == 27 ) break;
 	}

	// Release the capture device housekeeping
	cvReleaseCapture( &capture );
	cvDestroyWindow( WINDOW_NAME );
	return 0;
}
