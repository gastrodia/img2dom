#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
  VideoCapture capture("test.mp4");
  Mat edges;
  while(1){
    Mat frame;
    capture>>frame;

    cvtColor(frame,edges,COLOR_BGR2GRAY);
    blur(edges,edges,Size(7,7));
    Canny(edges,edges,0,30,3);
    imshow("read video",edges);
    waitKey(30);
  }

  waitKey(0);
  return 0;
}