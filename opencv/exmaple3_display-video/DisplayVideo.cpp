#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
  VideoCapture capture("test.mp4");

  while(1){
    Mat frame;
    capture>>frame;
    imshow("read video",frame);
    waitKey(30);
  }

  waitKey(0);
  return 0;
}