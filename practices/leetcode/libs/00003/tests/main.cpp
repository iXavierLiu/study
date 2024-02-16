#include "Solution.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

class NO_00003 : public testing::Test
{
protected:
	void Check(std::string&& s, size_t answer)
	{
		ASSERT_EQ(solution.lengthOfLongestSubstring(s), answer);
	}

	Solution solution;
};

TEST_F(NO_00003, 0)
{
	Check("abcabcbb", 3);
}
TEST_F(NO_00003, 1)
{
	Check("bbbbb", 1);
}
TEST_F(NO_00003, 2)
{
	Check("pwwkew", 3);
}
TEST_F(NO_00003, 3)
{
	Check("dvdf", 3);
}
