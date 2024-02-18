#include "Solution.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

class NO_00001 : public testing::Test
{
protected:
	void Check(vector<int>&& nums, int target, vector<int> answer)
	{
		this->nums = nums;
		result = solution.twoSum(this->nums, target);
		ASSERT_THAT(result, UnorderedElementsAreArray(answer));
	}

	Solution solution;
	vector<int> nums;
	vector<int> result;
};

TEST_F(NO_00001, 0)
{
	Check({ 2, 7, 11, 15 }, 9, { 0, 1 });
}

TEST_F(NO_00001, 1)
{
	Check({ 3, 2, 4 }, 6, { 1, 2 });
}

TEST_F(NO_00001, 2)
{
	Check({ 3, 3 }, 6, { 0, 1 });
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
	ASSERT_THAT(data, Not(Not(UnorderedElementsAreArray({ 2, 0, 1 }))));
}