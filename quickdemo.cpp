#include "quickdemo.h"
#include "opencv2/opencv.hpp"

void QuickDemo::colorSpace_Demo(Mat& image) {//图像的色彩空间转换
	Mat gray, hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);//将图像转为“hsv”格式的图像，转换后的图像叫做“hsv”。
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("original", image);
	imshow("hsv", hsv);
	imshow("gray", gray);

	imwrite("E:\\02LearnDownload\\08OpencvSelf\\02PracticeOpencvCode\\hsv_saved.PNG", hsv);
	imwrite("E:\\02LearnDownload\\08OpencvSelf\\02PracticeOpencvCode\\gray_saved.PNG", gray);
}

void QuickDemo::matcreation_demo(Mat& image) {//图像对象的创建与赋值
	Mat m1, m2;
	m1 = image.clone();	
	image.copyTo(m2);

	imshow("m1", m1);
	imshow("m2", m2);

	Mat m3 = Mat::ones(Size(400,400),CV_8UC3);//创建m3这个矩阵
	m3 = Scalar(255, 0, 0);
	std::cout << "m3.width:" << m3.cols << "  m3.height:" << m3.rows << "  m3.channels:" << m3.channels() << endl;


}
void QuickDemo::pixel_visit_demo(Mat& image) {//图像对象的读写操作
	int w = image.cols;
	int h = image.rows;
	int dim = image.channels();

#if 0 //用at进行读写操作
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			if (dim == 1) { //灰度图像
				int pv = image.at<uchar>(row, col);//将坐标(row, col)的像素读到pv中去
				image.at<uchar>(row, col) = 255 - pv;
			}
			if (dim == 3) { //彩色图像
				Vec3b bgr = image.at<Vec3b>(row, col);
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}
	}
	imshow("ouput", image);
#endif
	
#if 1//用 指针 进行读写操作
	for (int row = 0; row < w; row++) {
		uchar* current_row = image.ptr<uchar>(row);//获取当前行的指针
		for (int col = 0; col < h; col++) {
			if (dim == 1) {//灰度图像的操作
				int pv = *current_row;
				*current_row++ = 255 - pv;
			}
			if (dim == 3) {
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}
	imshow("ouput", image);

#endif



}