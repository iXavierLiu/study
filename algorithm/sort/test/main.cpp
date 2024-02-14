#include <iostream>
#ifdef WIN32
#include <io.h>
#else
#include <unistd.h>
#endif
#include <string.h>
#include <map>
#include "Test.h"
#include "../src/MySort.h"
#define MAX_SIZE 100000

std::map<const char*, bool(*)(int*arr, unsigned int len)> funPtrMap =
{
	{ "bubbleSort", MySort::bubbleSort },
	{ "insertionSort", MySort::insertionSort },
	{ "mergeSort", MySort::mergeSort },
	{ "quickSort", MySort::quickSort },
	{ "radixSort", MySort::radixSort },
	{ "selectionSort", MySort::selectionSort },
	{ "shellSort", MySort::shellSort }
};

int testCase(std::pair<const char*, bool(*)(int*arr, unsigned int len)> funPtrPair, const int data[], const unsigned int size)
{
	double timeUse;
	//用于排序临时的变量
	int* tmp = (int*)malloc(sizeof(int)*size);
	memcpy(tmp, data, sizeof(int)*size);

	std::cout << "testing " << funPtrPair.first << " with " << size << " data." << std::endl;
	timeUse = Test::doTest(tmp, size, funPtrPair.second);
	std::cout << "testing " << funPtrPair.first << " complete." << std::endl;

	char fileName[32];
	strcpy(fileName, funPtrPair.first);
	strcat(fileName, ".txt");
	Test::saveFile(fileName, tmp, size);
	std::cout << "time use: " << timeUse << " s." << std::endl << std::endl;

	free(tmp);
	return true;
}
int main(int argc, char*argv[])
{
	unsigned int readSize = MAX_SIZE;
	int* readData = (int*)malloc(sizeof(int)*readSize);

	// 文件不存在
	if (access("testData.txt", 0) != 0)
	{
		// 生成并保存
		std::cout << "generating " << readSize << " pieces of data." << std::endl;
		Test::generateData(readData, readSize);
		std::cout << "generate complete." << std::endl;
		Test::saveFile("testData.txt", readData, readSize);
	}
	else
	{
		// 加载文件
		std::cout << "reading file." << std::endl;
		Test::readFile("testData.txt", readData, readSize, MAX_SIZE);
		std::cout << "read " << readSize << " pieces of data complete." << std::endl;
	}

	std::cout << std::endl << "--------------------" << std::endl << std::endl;

	for (auto sortFun : funPtrMap)
	{
		testCase(sortFun, readData, readSize);
	}
	std::cout << "done" << std::endl;

	free(readData);
	getchar();
	return 0;
}
