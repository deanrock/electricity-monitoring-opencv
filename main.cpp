#include <cv.h>
#include <highgui.h> 
#include <stdio.h>  
// A Simple Camera Capture Framework 
int main() {
	CvCapture* capture = cvCaptureFromCAM( CV_CAP_ANY );
	if ( !capture ) {
		fprintf( stderr, "ERROR: capture is NULL \n" );
		getchar();
		return -1;
	}
	// Create a window in which the captured images will be presented
	//cvNamedWindow( "mywindow", CV_WINDOW_AUTOSIZE );
	// Show the image captured from the camera in the window and repeat
	while ( 1 ) {
		// Get one frame
		IplImage* frame = cvQueryFrame( capture );
		if ( !frame ) {
		fprintf( stderr, "ERROR: frame is null...\n" );
		getchar();
		break;
		}

		//process image
		CvRect old_roi = cvGetImageROI(frame); 
		//311x204
        cvSetImageROI(frame, cvRect(290,185,330,215)); 
        CvScalar c = cvAvg(frame); 
		//std::cout << c.val[0] << " " << c.val[1] << " " << c.val[2] << " " << c.val[3] << " " << std::endl;
		std::cout<<c.val[1]<<std::endl;
		cvSetImageROI(frame,old_roi); // reset old roi 

		//cvShowImage( "mywindow", frame );
		// Do not release the frame!
		//If ESC key pressed, Key=0x10001B under OpenCV 0.9.7(linux version),
		//remove higher bits using AND operator
		if ( (cvWaitKey(10) & 255) == 27 ) break;
	}
	// Release the capture device housekeeping
	cvReleaseCapture( &capture );
	//cvDestroyWindow( "mywindow" );
	return 0;
}