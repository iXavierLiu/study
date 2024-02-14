#include "Solution.h"

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	vector<int> ans;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (auto it = nums.begin() + i + 1;; ++it)
		{
			it = find(it, nums.end(), target - nums[i]);
			if (it == nums.end()) break;
			auto index = distance(nums.begin(), it);
			if (find(ans.begin(), ans.end(), index) != ans.end()) continue;
			ans.push_back(i);
			ans.push_back(index);
		}
	}
	return ans;
}