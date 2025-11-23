#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//定义一些图像处理方法，是类的函数。
class QuickDemo {
public:
	void colorSpace_Demo(Mat& image); //图像的色彩空间转换
	void matcreation_demo(Mat& image); //图像对象的创建和赋值 
	void pixel_visit_demo(Mat& image); //图像像素的读写操作

};
