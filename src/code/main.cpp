#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <experimental/filesystem>
#include <windows.h>

using namespace cv;
using namespace std;
namespace fs = std::experimental::filesystem;
typedef Point3_<uint8_t> Pixel;

string GetPathToFile(string str);
int main(int argc, char** argv)
{
	SYSTEMTIME time;

	string path_str = GetPathToFile("src/images/wood.jpg");
	cout << path_str << endl;
	string path_ball = GetPathToFile("src/images/blue_ball.png");
	Mat image1 = imread(path_str, IMREAD_UNCHANGED);
	Mat ball = imread(path_ball, IMREAD_UNCHANGED);
	cout << ball.channels() << endl;
	if (!image1.data || !ball.data)                              
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	imshow("is", image1);
	Mat background(1000, 1000, CV_8UC3, cv::Scalar(150));


	Vec3b vec = Vec3b(50,50,50);
	GetSystemTime(&time);
	SYSTEMTIME prevTime;
	int32_t r_loc = 5;
	int32_t c_loc = 5;
	int32_t size = 8;
	while (true) {
		prevTime = time;
		GetSystemTime(&time);
		cout << prevTime.wMilliseconds - time.wMilliseconds << endl;
		
		for (int r = r_loc; r < background.rows && r < r_loc+size; r++) {
			for (int c = c_loc; c < background.cols && c < c_loc + size; c++) {
				background.at<Vec3b>(r, c) = vec;
			}
		}
		imshow("bg", background);
		r_loc++;
		c_loc++;
		waitKey(1000/60);
	}
	waitKey(0);         
	return 0;
}
string GetPathToFile(string str) {
	stringstream path;
	path << fs::current_path() << "/" <<str;
	string path_str = path.str();
	replace(path_str.begin(), path_str.end(), '\\', '/');
	return path_str;
}
