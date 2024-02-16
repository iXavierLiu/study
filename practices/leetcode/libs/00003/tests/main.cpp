#include "Solution.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

class NO_00003 : public testing::Test
{
protected:
	Solution solution;
};

TEST_F(NO_00003, 0)
{
	ASSERT_EQ(solution.lengthOfLongestSubstring("abcabcbb"), 3);
}
TEST_F(NO_00003, 1)
{
	ASSERT_EQ(solution.lengthOfLongestSubstring("bbbbb"), 1);
}
TEST_F(NO_00003, 2)
{
	ASSERT_EQ(solution.lengthOfLongestSubstring("pwwkew"), 3);
}
