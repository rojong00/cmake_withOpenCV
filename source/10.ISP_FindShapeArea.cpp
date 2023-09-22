#pragma once
#include "ISP.hpp"

int main()
{
    string filePath = "D:\\opencv\\thirdparty\\data\\shapes.jpg";
	Mat src_color = imread(filePath);
	Mat src_hsv = Mat::zeros(src_color.size(), CV_8UC3);
	Mat src_hsv_Red_threshold = Mat::zeros(src_color.size(), CV_8UC1);
	Mat src_hsv_Red_1_threshold = Mat::zeros(src_color.size(), CV_8UC1);
	Mat src_hsv_Red_2_threshold = Mat::zeros(src_color.size(), CV_8UC1);
	cvtColor(src_color, src_hsv, COLOR_BGR2HSV);

	const int max_value_H = 360 / 2;
	const int max_value = 255;
	int low_H = 0, low_S = 0, low_V = 0;
	int high_H = max_value_H, high_S = max_value, high_V = max_value;
	low_H = 20;
	high_H = 110;
	low_S = 50;
	high_S = 150;
	low_V = 40;
	high_V = 110;
	inRange(src_hsv, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), src_hsv_Red_1_threshold);
	low_H = 165;
	high_H = 180;
	inRange(src_hsv, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), src_hsv_Red_2_threshold);
	addWeighted(src_hsv_Red_1_threshold, 1, src_hsv_Red_2_threshold, 1, 1, src_hsv_Red_threshold);


	threshold(src_hsv_Red_threshold, src_hsv_Red_threshold, 128, 255, ThresholdTypes::THRESH_BINARY);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(src_hsv_Red_threshold, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	//pixels   ....   regions (MASK)  ....  contours (POINTS)
	//origin          sub_area (1or0)       point x,y[N] + point x,y[N] + point x,y[N]

	//int arr[row][col];
	//int contours[count][nth Point]
	//contours[0].at(0).x;
	//contours[0].at(0).y;

	RNG rng(12345);
	Mat drawing = src_color.clone();
	for (size_t i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		color = Scalar(0, 0, 0);
		//drawContours(drawing, contours, (int)i, color, 5, LINE_8, hierarchy, 0);

		double area = contourArea(contours[i]);
		auto rt = boundingRect(contours[i]);
		string msg = "Area = " + to_string(area);
		putText(drawing, msg, Point(50, 100 + i * 20), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0));
		cv::rectangle(drawing, rt, Scalar(0, 0, 0), 1);
	}




    return 0;
}