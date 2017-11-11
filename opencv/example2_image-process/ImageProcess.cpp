#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
  Mat srcImage = imread("/home/allay/图片/2017-08-23 15-45-16屏幕截图.png");
  imshow("source image", srcImage);

  //腐蚀
  Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
  Mat erodImage;
  erode(srcImage, erodImage, element);
  imshow("after erode", erodImage);

  //模糊
  Mat blurImage;
  blur(srcImage, blurImage, Size(7, 7));
  imshow("after blur", blurImage);

  //边缘监测
  Mat edge,grayImage;
  cvtColor(srcImage,grayImage,CV_RGB2GRAY);
  blur(grayImage,edge,Size(3,3));
  //erode(grayImage,edge,element);
  Canny(edge,edge,3,9,3);
  imshow("edge image",edge);

  waitKey(0);
  return 0;
}