/*
1002 写出这个数(20分)
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10
​100
​​ 。

输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int main() {
    char n[101];
    cin.getline(n, 101);
    int count = 0;
    const char* map[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
    for (int len = strlen(n), i = 0; i < len; ++i) {
        count += n[i] - '0';
    }
    int m;
    for (int i = log10(count); i > 0; --i) {
        m = count / (int)pow(10, i);
        count %= (int)pow(10, i);
        cout << map[m] << " ";
    }
    cout << map[count % 10] << endl;
    return 0;
}