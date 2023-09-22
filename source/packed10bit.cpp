#pragma once
#include <iostream>
#include <vector>
#include <string>
//class Ipacked;
class packedBit //: public Ipacked
{
public://접근지정자
	//Ctor
	packedBit() { std::cout << "Ctor" << std::endl; }
	~packedBit() { std::cout << "Dtor" << std::endl; }
public:
	int SetData(int p1 = 0, int p2 = 0, int p3 = 0, int p4 = 0, int lsb = 0) {
		a = p1; b = p2; c = p3; d = p4; packed = lsb;
		return 1;
	}
	int SetData(
		const uint8_t* const p1 = nullptr,
		const uint8_t* const p2 = nullptr,
		const uint8_t* const p3 = nullptr,
		const uint8_t* const p4 = nullptr,
		const uint8_t* const lsb = nullptr)
	{
		a = *p1; b = *p2; c = *p3; d = *p4; packed = *lsb;
		return 1;
	}
	int Convert10bitTo2Bytes()
	{
		A = B = C = D = 0x00;
		std::cout << "=======  Convert10bitTo2Bytes  =======" << std::endl;
		A = (a << 2) | ((packed >> 6) & 0x03) & 0xFFFF;
		B = ((b << 2) | (packed >> 4) & 0x03) & 0xFFFF;
		C = ((c << 2) | (packed >> 2) & 0x03) & 0xFFFF;
		D = ((d << 2) | (packed >> 0) & 0x03) & 0xFFFF;
		return 1;
	}
	int Convert12bitTo2Bytes()
	{
		A = B = C = D = 0x00;
		std::cout << "=======  Convert12bitTo2Bytes  =======" << std::endl;
		A = ((a << 4) | (packed >> 4) & 0x0F) & 0xFFFF;
		B = ((b << 4) | (packed >> 0) & 0x0F) & 0xFFFF;
		return 1;
	}
	int GetData(
		uint16_t* const p1,
		uint16_t* const p2,
		uint16_t* const p3,
		uint16_t* const p4)
	{
		if (p1 != nullptr) *p1 = A;
		if (p2 != nullptr) *p2 = B;
		if (p3 != nullptr) *p3 = C;
		if (p4 != nullptr) *p4 = D;
		return 1;
	}
	int ShowResult()
	{
		std::cout << "A = " << A << std::endl;
		std::cout << "B = " << B << std::endl;
		std::cout << "C = " << C << std::endl;
		std::cout << "D = " << D << std::endl;
		return 1;
	}
private:
	uint8_t a = 0x12;
	uint8_t b = 0x35;
	uint8_t c = 0xB3;
	uint8_t d = 0x1A;
	uint8_t packed = 0xAB;

	uint16_t A = 0x0000;
	uint16_t B = 0x0000;
	uint16_t C = 0x0000;
	uint16_t D = 0x0000;

protected:

};

int main()
{
	//
	/*
	txt -> code -> app -> pattern -> effective C++
	   -> mordern effective c++ -> arch SW -> generic programming
	*/
	//
	std::cout << "Hello Im SangSoo Noh!\n";

	uint8_t a = 0x12;
	uint8_t b = 0x35;
	uint8_t c = 0xB3;
	uint8_t d = 0x1A;
	uint8_t packed = 0xAB;

	packedBit pck;//선언...객체화...인스턴스화->생성자 호출
	pck.SetData(&a, &b, &c, &d, &packed);
	pck.Convert10bitTo2Bytes();
	uint16_t A = 0x0000;
	uint16_t B = 0x0000;
	uint16_t C = 0x0000;
	uint16_t D = 0x0000;
	pck.GetData(&A, &B, &C, &D);
	pck.ShowResult();

	
	a = 0x12;
	b = 0x35;
	packed = 0xB3;
	pck.SetData(&a, &b, &c, &d, &packed);
	pck.Convert12bitTo2Bytes();
	A = B = C = D = 0x0000;
	pck.GetData(&A, &B, &C, &D);
	pck.ShowResult();
	//std::cout << "A = " << A << std::endl;
	//std::cout << "B = " << B << std::endl;
	//std::cout << "C = " << C << std::endl;
	//std::cout << "D = " << D << std::endl;
	return 1;
}
