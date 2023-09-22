#ifndef __ISP_HPP__
#define __ISP_HPP__

#include "IMatrixProc.h"

class ISP : public IMatrixProc
{
    Mat srcImg;
    Mat srcImgY;

    uint8_t a = 0x12;
    uint8_t b = 0x35;
    uint8_t c = 0xB3;
    uint8_t d = 0x1A;
    uint8_t packed = 0xAB;

    uint16_t A = 0x0000;
    uint16_t B = 0x0000;
    uint16_t C = 0x0000;
    uint16_t D = 0x0000;
public:
    ISP() { std::cout << "ISP::Ctor" << std::endl; };
    ~ISP() { std::cout << "ISP::Dtor" << std::endl; };
    int Cols() { return srcImg.cols; }
    int Rows() { return srcImg.rows; }
    int Channels() { return srcImg.channels(); }
    Mat LoadImg(const string& filepath) override;

    //convert
    int Convert_RGB2Gray(const uchar* const src, uchar* const dst,
        const int& width, const int& height) override;
    int Convert_RGB2HSV(const Mat& src, Mat& dst) override;

    //histogram
    int Histogram(const uchar* const pGray,
        const int& width, const int& height,
        uchar* const phisto, const int& histoSz);

    int HistogramEq(const uchar* const pGray, // src
        uchar* const pGrayEq, // dst
        const int& width, const int& height);

    int HistogramEqOpenCV(const Mat src, Mat dst);

    double GetPSNR(const Mat& const pGrayRef, //reference
        const Mat& const pGray, //current for difference
        const int& width, const int& height) override;

	// quantifiable figures by opencv
    double GetPSNRopenCV(const Mat src, Mat dst, double MAX=255);

    //algo
    int ProcThreshold(const Mat& src, Mat& dst,
        int minVal, int maxVal);
    int ProcThreshold(const uchar* const pGray, uchar* const pDst,
        const int& width, const int& height, const int& channels,
        int minVal, int maxVal);

    //decode
    int Convert_packed10bitTo16bit(
        const uint8_t* const p1 = nullptr,
        const uint8_t* const p2 = nullptr,
        const uint8_t* const p3 = nullptr,
        const uint8_t* const p4 = nullptr,
        const uint8_t* const lsb = nullptr,
        uint16_t* const _p1 = nullptr,
        uint16_t* const _p2 = nullptr,
        uint16_t* const _p3 = nullptr,
        uint16_t* const _p4 = nullptr);
    int Convert_packed12bitTo16bit(
        const uint8_t* const p1 = nullptr,
        const uint8_t* const p2 = nullptr,
        const uint8_t* const lsb = nullptr,
        uint16_t* const _p1 = nullptr,
        uint16_t* const _p2 = nullptr);

    // filter proc
    int filterProc(const uchar* const pGray, //src
        uchar* const pGrayDst, //dst
        const int& width, const int& height,
        const float* const pKernel,
        const int& widthKernel, const int& heightKernel) override;

    //independent
    void hello();
    };
#endif // !ISP_H
