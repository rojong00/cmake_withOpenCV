#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::cout << "Histogram Algorithm\n";
	int arr[] = { 
		2,2,3,6,87,
		4,2,3,68,8,
		8,8,6,7,65,
		6,8,6,8,7,
		1,5,4,5,8 };

	int len = sizeof(arr) / sizeof(arr[0]);
	//bins
	const int size = 88;
	int bins[size] = { 0, };//static <-> dynamic
	
	//a++
	//l-value    =    r-value
	//bins[2] = 0;//0 .....arr[0], [1], [6]....->  bins[arr[0]] = 0;//0
	//bins[2]++;//0->1.....bins[arr[0]]++;//0->1
	//bins[2]++;//1->2.....bins[arr[1]]++;//1->2
	//bins[2]++;//2->3.....bins[arr[6]]++;//2->3

	for (size_t i = 0; i < len; i++) bins[arr[i]]++;
	
	for (size_t i = 0; i < size; i++)
	{
		if (bins[i] > 0)
		{
			std::cout << i << " |";
			for (size_t bin = 0; bin < bins[i]; bin++)
			{
				std::cout << "=";
			}
			std::cout << "(" << bins[i] << ")" << std::endl;
		}
	}

	return 1;
}