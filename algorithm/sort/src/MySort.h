#ifndef __MySort_h__
#define __MySort_h__
#include "MySort.h"
class MySort{
private:
	typedef unsigned int uint;
	static void swap(int arr[], const uint a, const uint b);
public:
	MySort();
	// Ã°ÅİÅÅĞò
	static bool bubbleSort(int arr[],const uint len);

	// ²åÈëÅÅĞò
	static bool insertionSort(int arr[], const uint len);

	// ¹é²¢ÅÅĞò
	static bool mergeSort(int arr[], const uint len);

	// ¿ìËÙÅÅĞò
	static bool quickSort(int arr[], const uint len);

	// »ùÊıÅÅĞò
	static bool radixSort(int arr[], const uint len);

	// Ñ¡ÔñÅÅĞò
	static bool selectionSort(int arr[], const uint len);

	// Ï£¶ûÅÅĞò
	static bool shellSort(int arr[], const uint len);

};
#endif