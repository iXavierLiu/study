#include "Solution.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

class NO_00001 : public testing::Test
{
protected:
	void Run(vector<int>&& nums, int target)
	{
		this->nums = nums;
		result = solution.twoSum(this->nums, target);
	}

	Solution solution;
	vector<int> nums;
	vector<int> result;
};

TEST_F(NO_00001, 0)
{
	Run({ 2, 7, 11, 15 }, 9);
	ASSERT_EQ(result.size(), 2);
	ASSERT_THAT(result, UnorderedElementsAreArray({ 0, 1 }));
}

TEST_F(NO_00001, 1)
{
	Run({ 3, 2, 4 }, 6);
	ASSERT_THAT(result, UnorderedElementsAreArray({ 1, 2 }));
}

TEST_F(NO_00001, 2)
{
	Run({ 3, 3 }, 6);
	ASSERT_THAT(result, UnorderedElementsAreArray({ 0, 1 }));
}

TEST_F(NO_00001, VALIDATION)
{
	vector<int> data;
	data = { 0, 1 };
	ASSERT_THAT(data, UnorderedElementsAreArray({ 0, 1 }));
	data = { 1, 0 };
	ASSERT_THAT(data, UnorderedElementsAreArray({ 0, 1 }));
	data = { 0, 1, 2 };
	ASSERT_THAT(data, Not(UnorderedElementsAreArray({ 0, 1 })));
}