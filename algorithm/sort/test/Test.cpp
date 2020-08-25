#include <fstream>
#include <random>
#include <ctime>
#include "Test.h"


void Test::generateData(int data[], unsigned int size)
{
	std::default_random_engine random;
	std::uniform_int_distribution<unsigned> range(0, 99999999);
	random.seed(time(NULL));
	for (unsigned int i = 0; i < size; ++i)
		data[i] = range(random);
}

bool Test::saveFile(const char*fileNaem, int data[], unsigned int size)
{
	std::ofstream outfile;
	outfile.open(fileNaem, std::ios::out);
	if (!outfile.is_open())return false;
	for (unsigned int i = 0; i < size; i++)
		outfile << data[i] << std::endl;
	outfile.close();
	return true;
}

bool Test::readFile(const char*fileName, int data[], unsigned int &size, unsigned int maxSize)
{
	maxSize = maxSize ? maxSize : ~0;
	std::ifstream infile;
	infile.open(fileName, std::ios::in);
	if (!infile.is_open())return false;
	for (size = 0; size < maxSize&&!infile.eof(); ++size)
		infile >> data[size];
	infile.close();
	return true;
}

double Test::doTest(int data[], unsigned int size, bool(*fun)(int arr[], const unsigned int len))
{
	time_t time_start = clock();
	fun(data, size);
	time_t time_end = clock();
	return (time_end - time_start) / (double)CLOCKS_PER_SEC;
}
