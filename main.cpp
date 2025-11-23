#include <iostream>
#include "quickdemo.h"
//using namespace std;
//using namespace cv;

#if 0 //第一课.图像的读取与显示
int main(void) {
	Mat src = imread("E:\\02LearnDownload\\08OpencvSelf\\02PracticeOpencvCode\\lena.png", IMREAD_UNCHANGED);
	if (src.empty()) {//检查图像是否为空
		printf("could not load image...\n");
		return -1;
}
	namedWindow("input", WINDOW_FREERATIO);//创建一个窗口，就可以完整的显示分辨率较大的图片了,可以随意调整图
	imshow("input", src);


	//system("pause");//写这个代码，图片不显示。
	waitKey(0);
	return 0;
}
#endif

#if 0 //第二课.图像的色彩空间转换
int main(void) {
	Mat src = imread("E:\\02LearnDownload\\08OpencvSelf\\02PracticeOpencvCode\\lena.png");
	if (src.empty()) {
		printf("could not load image \n");
		return -1;
	}
	QuickDemo qd;
	qd.colorSpace_Demo(src);


	waitKey(0);
	return 0;
}
#endif

#if 0 //第三课.图像对象的的创建与赋值
int main(void) {
	Mat src = imread("E:\\02LearnDownload\\08OpencvSelf\\02PracticeOpencvCode\\lena.png");
	if (src.empty()) {
		printf("could not load image \n");
		return -1;
	}
	QuickDemo qd;
	qd.matcreation_demo(src);


	waitKey(0);
	return 0;
}
#endif

#if 1 //第四课.图像对象的读写操作
int main(void) {
	Mat src = imread("E:\\02LearnDownload\\08OpencvSelf\\02PracticeOpencvCode\\lena.png");
	if (src.empty()) {
		printf("could not load image \n");
		return -1;
	}
	imshow("src", src);
	QuickDemo qd;
	qd.pixel_visit_demo(src);


	waitKey(0);
	return 0;
}
#endif




