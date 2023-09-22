#include "ISP.hpp"
#include <algorithm>
#include <vector>


Mat ISP::LoadImg(const string& filepath)
{
    srcImg = imread(filepath);

	// case:color
	if (srcImg.channels() == 3) cvtColor(srcImg, srcImgY, ColorConversionCodes::COLOR_BGR2GRAY);
	// case:mono,gray
	else
	{
		//srcImgY = srcImg.clone();  // 깊은 복사
		srcImgY = srcImg; // 얕은복사
	}

    return srcImg;
}


int ISP::Convert_RGB2Gray(const uchar* const src, uchar* const dst,
	const int& width, const int& height)
{
	// width & height is attr of rgb_src
	int channel = 3;
	//uchar* pimg_src = src.data;
	//uchar* pimg_dst = dst.data;

	// i+0:B, i+1:G, i+2:R
	for (int i = 0; i < height * width* channel; i += 3)
		dst[i / 3] = 0.299 * src[i + 2] + 0.587 * src[i + 1] + 0.114 * src[i];

	return 1;
}

int ISP::Convert_RGB2HSV(const Mat& src, Mat& dst)
{
	const int max_value_H = 360 / 2;
	const int max_value = 255;
	const String window_capture_name = "Video Capture";
	const String window_detection_name = "Object Detection";
	int low_H = 0, low_S = 0, low_V = 0;
	int high_H = max_value_H, high_S = max_value, high_V = max_value;
	
	//cap >> frame;
	Mat frame, frame_HSV, frame_threshold;
	frame = src;
	if (frame.empty())
	{
		return 0;
	}
	// Convert from BGR to HSV colorspace
	cvtColor(frame, frame_HSV, COLOR_BGR2HSV);
	// Detect the object based on HSV Range Values
	inRange(frame_HSV, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), frame_threshold);
	// Show the frames
	imshow(window_capture_name, frame);
	imshow(window_detection_name, frame_threshold);
	char key = (char)waitKey(30);
	if (key == 'q' || key == 27)
	{
		return 0;
	}
	return 1;
}


int ISP::Histogram(const uchar* const pGray,
	const int& width, const int& height,
	uchar* const phisto, const int& histoSz)
{
	//int* arrHistogram = new int[his] {0, };
	for (int i = 0; i < width * height; i++) if ( histoSz >= width*height ) phisto[pGray[i]]++;

	return 1;
}

int ISP::HistogramEq(const uchar* const pGray, // src.data
	uchar* const pGrayEq,					   // dst
	const int& width, const int& height)
{
	int histoTMP[256]{ 0, }; memset(histoTMP, 0, 256 * sizeof(int)); // FOR 8 BIT COLOUR FORMAT (RGB)
	int histoEQ[256]{ 0, }; memset(histoEQ, 0, 256 * sizeof(int)); // FOR 8 BIT COLOUR FORMAT (RGB)
    for (int i = 0; i < width * height ; ++i ) histoTMP[pGray[i]]++;
	
	double accumulation = 0;
	for (int i = 0; i < width * height; ++i)
	{
		accumulation += histoTMP[i];
		histoEQ[i] = (255 * accumulation) / (width * height);
	}
	
	for (int i = 0; i < width * height; ++i)
	{
		pGrayEq[i] = histoEQ[pGray[i]];
	}

	return 1;
}

int ISP::HistogramEqOpenCV(const Mat src, Mat dst)
{
	cv::equalizeHist(src, dst);

	return 1;
}

double ISP::GetPSNR(const Mat& const pGrayRef, //reference
	const Mat& const pGray, //current for difference
	const int& width, const int& height)
{
	Mat enhanced_img = pGray; 
	Mat src_img = pGrayRef;
	Mat abs_diff;
	absdiff(enhanced_img, src_img, abs_diff);
	abs_diff.convertTo(abs_diff, CV_32F); //CV_32F datatype : 32-bit floating-point number
	abs_diff = abs_diff.mul(abs_diff);

	Scalar s_sum = cv::sum(abs_diff);
	double sum = s_sum.val[0];
	double MSE = 0, PSNR = 0;
	if (sum <= 1e-10)
	{
		MSE = PSNR = 0;
	}
	else
	{
		MSE = sum / (double)(src_img.channels() * src_img.total());
		PSNR = 10.0 * log10((255 * 255) / MSE);
	}
	string msg_1 = "";
	msg_1 = "tmp // MSE = " + to_string(MSE) + " PSNR = " + to_string(PSNR);

	std::cout << msg_1 << '\n';
	return 1.0;
}

double ISP::GetPSNRopenCV(const Mat src, Mat dst, double MAX)
{
	return cv::PSNR(src, dst, MAX);
}

int ISP::ProcThreshold(const Mat& src, Mat& dst,
	int minVal, int maxVal=255)
{
	cv::threshold(src, dst, minVal, maxVal, ThresholdTypes::THRESH_BINARY);
	/*
	int height = srcImg.rows;
	int width = srcImg.cols;
	uchar* pimg_src = src.data;
	uchar* pimg_dst = dst.data;

	for (int i = 0; i < width * height; i++)
	{
		if (pimg_src[i] <= minVal) pimg_dst[i] = 0;
		else pimg_dst[i] = 255;
	}
	*/
	return 1;
}


int ISP::ProcThreshold(const uchar* const pGray, uchar* const pDst,
	const int& width, const int& height, const int& channels,
	int minVal, int maxVal)
{
	/*
	int height = pGray.rows;
	int width = pGray.cols;
	uchar* pimg_src = pGray.data;
	uchar* pimg_dst = pDst.data;
	*/
	for (int i = 0; i < width * height; i++)
	{
		if (pGray[i] <= minVal) pDst[i] = 0;
		else pDst[i] = 255;
	}
	
	return 1;
}


int ISP::Convert_packed10bitTo16bit(
	const uint8_t* const p1,
	const uint8_t* const p2,
	const uint8_t* const p3,
	const uint8_t* const p4,
	const uint8_t* const lsb,
	uint16_t* const _p1,
	uint16_t* const _p2,
	uint16_t* const _p3,
	uint16_t* const _p4)
{
	*_p1 = *_p2 = *_p3 = *_p4 = 0x0000;
	std::cout << "=======  Convert8bitTo10bits  =======" << std::endl;
	*_p1 = (*p1 << 2) | ((*lsb >> 0) & 0x03) & 0xFFFF;
	*_p2 = (*p2 << 2) | ((*lsb >> 2) & 0x03) & 0xFFFF;
	*_p3 = (*p3 << 2) | ((*lsb >> 4) & 0x03) & 0xFFFF;
	*_p4 = (*p4 << 2) | ((*lsb >> 6) & 0x03) & 0xFFFF;

	return 1;
}


int ISP::Convert_packed12bitTo16bit(
	const uint8_t* const p1,
	const uint8_t* const p2,
	const uint8_t* const lsb,
	uint16_t* const _p1,
	uint16_t* const _p2)
{
	*_p1 = *_p2 = 0x0000;
	std::cout << "=======  Convert12bitTo16bits  =======" << std::endl;
	*_p1 = (*p1 << 4) | ((*lsb >> 0) & 0x0F) & 0xFFFF;
	*_p2 = (*p2 << 4) | ((*lsb >> 4) & 0x0F) & 0xFFFF;

	return 1;
}


// filter proc
int ISP::filterProc(const uchar* const pGray, //src
	uchar* const pGrayDst, //dst
	const int& width, const int& height,
	const float* const pKernel,
	const int& widthKernel, const int& heightKernel)
{
	/*
	size_t* offset = new size_t[widthKernel * heightKernel];
	for (size_t f_row = 0; f_row < heightKernel; f_row++)
	{
		for (size_t f_col = 0; f_col < widthKernel; f_col++)
		{
			offset[f_row * heightKernel + f_col] = f_row * height + f_col;
		}
	}
	*/
	vector<int> v;
	for (size_t row = 0; row < height - heightKernel ; row++)
	{
		for (size_t col = 0; col < width - widthKernel; col++)
		{
			int idx = (row + heightKernel / 2) * width + (col + widthKernel / 2);
			int gv = pGray[idx];
			float conv_value = 0;
			
			v.clear();
			for (size_t offsetForMatrix = 0; offsetForMatrix < widthKernel*heightKernel ; offsetForMatrix++)
			{
				int quotient = offsetForMatrix / widthKernel;
				int remainder = offsetForMatrix % widthKernel;
				v.push_back( pGray[ (quotient * width + remainder) + row*width+col ] );
			}
			int lengthV = v.size();
			std::sort(v.begin(), v.begin()+lengthV);
			uint8_t median = v.at(lengthV / 2);			
			/*
			for (size_t offsetForMatrix = 0; offsetForMatrix < widthKernel * heightKernel; offsetForMatrix++)
			{
				int quotient = offsetForMatrix / widthKernel;
				int remainder = offsetForMatrix % widthKernel;
				conv_value += pKernel[offsetForMatrix] * pGray[ (quotient * width + remainder) + row*width+col ];
			}

			pGrayDst[idx] = static_cast<uchar>(conv_value);
			*/
			pGrayDst[idx] = median;
		}
	}

	return 1;
}



// 외부에서 접근 불가 => public으로 함수를 선언할 필요가 없다!
// => 사실 이런 함수는 public이 아닌 아예 private으로 선언하는 게 은닉성 성격에 더 적합!
// imatricproc* INSTANCE = new ISP()로 선언했을 때,
// 내부의 다른 함수에서 call 은 가능
void ISP::hello()
{
	std::cout << "HI!\n" << '\n';
}
