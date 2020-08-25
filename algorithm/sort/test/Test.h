class Test
{
public:
	static void generateData(int data[], const unsigned int size);
	static bool saveFile(const char*fileNaem, int data[], const unsigned int size);
	static bool readFile(const char*fileName, int data[], unsigned int &size, const unsigned int maxSize = 0);
	static double doTest(int data[], const unsigned int size, bool(* fun)(int arr[],const unsigned int len));
};