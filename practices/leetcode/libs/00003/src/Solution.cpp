#include "Solution.h"

#include <set>

int Solution::lengthOfLongestSubstring(string s)
{
	return lengthOfLongestSubstring_recurse(s);
}
/*
 * mark: 1/5
 * 无循环递归分割
 */
int Solution::lengthOfLongestSubstring_recurse(string s, size_t mark)
{
	if (s.size() <= 1) return s.size() + mark;

	auto pos = s.find(s.front(), 1);
	if (string::npos == pos) return lengthOfLongestSubstring_recurse(s.substr(1), 1 + mark);

	return max(lengthOfLongestSubstring_recurse(s.substr(0, pos), mark), lengthOfLongestSubstring_recurse(s.substr(1)));
}

/*
 * mark: 4/5
 * nomal的改进，单循环头尾指针递进
 */
int Solution::lengthOfLongestSubstring_dblPointer(string s)
{
	set<char> alpha;
	size_t result = 0;

	string::iterator left = s.begin();
	string::iterator right = left;

	while (right != s.end())
	{
		if (alpha.end() == alpha.find(*right))
		{
			alpha.insert(*right);
			++right;
			continue;
		}
		result = max(result, alpha.size());

		alpha.erase(*left++);
	}
	return max(result, alpha.size());
}

/*
 * mark: 2/5
 * 基本方法，双循环
 */
int Solution::lengthOfLongestSubstring_nomal(string s)
{
	set<char> alpha;
	size_t result = 0;

	for (string::iterator left = s.begin(); left != s.end(); ++left)
	{
		alpha.clear();
		for (string::iterator right = left; right != s.end(); ++right)
		{
			if (alpha.end() != alpha.find(*right)) break;

			alpha.insert(*right);
		}
		result = max(result, alpha.size());
	}

	return result;
}