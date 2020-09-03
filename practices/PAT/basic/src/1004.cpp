/*
 *
 * @file     1004.cpp
 * @author   errcodex
 * @brief
 * 3 cases passed on 9/3/2020 with 5ms max time use
 * and 424KB max space use.
 *
 */
#include <string.h>
#include <iostream>
#include <vector>

#pragma warning(disable : 4996)

using namespace std;

class Stu
{
public:
    Stu(string name, string no, int score) : score(score), name(name), no(no) {}
    void print() { cout << name << " " << no << endl; }
    int score;

private:
    string name;
    string no;
};

int main(int argc, char* argv[])
{
    int n;
    char str[30];
    char* p;

    cin.getline(str, 30);
    n = atoi(str);

    int min = 0;
    int max = 0;
    vector<Stu> stu;
    for (int i = 0; i < n; i++)
    {
        cin.getline(str, 30);

        p           = strtok(str, " ");
        string name = p;

        p         = strtok(NULL, " ");
        string no = p;

        p         = strtok(NULL, " ");
        int score = atoi(p);

        stu.push_back(Stu(name, no, score));

        max = score > stu[max].score ? i : max;
        min = score < stu[min].score ? i : min;
    }
    stu[max].print();
    stu[min].print();
    return 0;
}