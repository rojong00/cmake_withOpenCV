#pragma once

#include "Common.h"

class IMatrixProc
{
public:
	IMatrixProc() { std::cout << "IMatrix::Ctor" << std::endl; };
	virtual ~IMatrixProc() { std::cout << "IMatrix::Dtor" << std::endl; };

	virtual Mat LoadImg(const string& filepath) = 0;

	int Cols() { return srcImg.cols; }
	int Rows() { return srcImg.rows; }
	int Channels() { return srcImg.channels(); }
public:
	//algorithm
	virtual int ProcThreshold(const Mat& src, Mat& dst, int minVal, int maxVal = 255) = 0;
	virtual int ProcThreshold(const uchar* const pGray, uchar* const pDst,
		const int& width, const int& height, const int& channels,
		int minVal, int maxVal = 255) = 0;

	//histogram
	virtual int Histogram(const uchar* const pGray,
		const int& width, const int& height,
		uchar* const phisto, const int& histoSz) = 0;

	//histogram2
	virtual int HistogramEq(const uchar* const pGray, // src
		uchar* const pGrayEq, // dst
		const int& width, const int& height) = 0;

	virtual int HistogramEqOpenCV(const Mat src, Mat dst) = 0;

	// quantifiable figures
	virtual double GetPSNR(const Mat& const pGrayRef, //reference
		const Mat& const pGray, //current for difference
		const int& width, const int& height) = 0;

	// quantifiable figures by opencv
	virtual double GetPSNRopenCV(const Mat src, Mat dst, double MAX ) = 0;
		
	//convert
	virtual int Convert_RGB2Gray(const uchar* const pRGB, uchar* const pGray, const int& width, const int& height) = 0;
	virtual int Convert_RGB2HSV(const Mat& src, Mat& dst) = 0;

	//decode
	virtual int Convert_packed10bitTo16bit(
		const uint8_t* const p1 = nullptr,
		const uint8_t* const p2 = nullptr,
		const uint8_t* const p3 = nullptr,
		const uint8_t* const p4 = nullptr,
		const uint8_t* const lsb = nullptr,
		uint16_t* const _p1 = nullptr,
		uint16_t* const _p2 = nullptr,
		uint16_t* const _p3 = nullptr,
		uint16_t* const _p4 = nullptr) = 0;
	virtual int Convert_packed12bitTo16bit(
		const uint8_t* const p1 = nullptr,
		const uint8_t* const p2 = nullptr,
		const uint8_t* const lsb = nullptr,
		uint16_t* const _p1 = nullptr,
		uint16_t* const _p2 = nullptr) = 0;

	// filter
	virtual int filterProc(const uchar* const pGray, //src
		uchar* const pGrayDst, //dst
		const int& width, const int& height,
		const float* const pKernel,
		const int& widthKernel, const int& heightKernel) = 0;

private:
	Mat srcImg;
	Mat srcImgY;
};


