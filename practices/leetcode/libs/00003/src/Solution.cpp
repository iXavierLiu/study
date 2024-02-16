#include "Solution.h"

#include <set>
int Solution::lengthOfLongestSubstring(string s)
{
	set<char> alpha;
	size_t result = 0;
	auto it = s.begin();
	auto end = it;
	while (end != s.end())
	{
		if (alpha.end() == alpha.find(*end))
		{
			alpha.insert(*end);
			++end;
			continue;
		}
		result = result > alpha.size() ? result : alpha.size();

		alpha.erase(*it++);
	}
	return result > alpha.size() ? result : alpha.size();
}

int Solution::lengthOfLongestSubstring_0(string s)
{
	set<char> alpha;
	size_t result = 0;
	for (string::iterator it = s.begin(); it != s.end(); ++it)
	{
		auto end = it;
		alpha.clear();
		for (string::iterator c = it; c != s.end(); ++c)
		{
			if (alpha.end() != alpha.find(*c)) break;

			alpha.insert(*c);
		}
		result = result > alpha.size() ? result : alpha.size();
	}

	return result;
}