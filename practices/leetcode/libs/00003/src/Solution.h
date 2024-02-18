#include <string>

using namespace std;
class Solution
{
public:
	int lengthOfLongestSubstring(string s);
	int lengthOfLongestSubstring_recurse(string s, size_t mark = 0);
	int lengthOfLongestSubstring_nomal(string s);
	int lengthOfLongestSubstring_dblPointer(string s);
};