#include "Solution.h"

#include <map>

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	map<int, int> addends;
	for (int i = 0; i < nums.size(); ++i)
	{
		const int& addend = nums[i];

		// try to check if it is paired, then return indexes
		decltype(addends)::iterator it = addends.find(addend);
		if (it != addends.end()) return { it->second, i };

		// calc addend paired, then add it to `addends` list
		addends.insert(decltype(addends)::value_type(target - addend, i));
	}
	return {};
}