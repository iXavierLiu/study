#include "Solution.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

class NO_00002 : public testing::Test
{
protected:
	void Test(vector<int> v1, vector<int> v2, vector<int> result)
	{
		ASSERT_TRUE(Equals(solution.addTwoNumbers(Build(v1), Build(v2)), Build(result)));
	}
	bool Equals(ListNode* ln1, ListNode* ln2)
	{
		while (ln1 && ln2)
		{
			if (ln1->val != ln2->val) return false;
			ln1 = ln1->next;
			ln2 = ln2->next;
		}
		if (ln1 || ln2) return false;
		return true;
	}

	virtual void TearDown() override
	{
		Delete(ln1);
		Delete(ln2);
	}

	void Delete(ListNode* ln)
	{
		while (ln)
		{
			auto p = ln->next;
			delete ln;
			ln = p;
		}
	}
	ListNode* Build(vector<int> v)
	{
		ListNode* ln = new ListNode(*v.begin());
		ListNode* p = ln;
		for_each(v.begin() + 1, v.end(), [&p](int dig) {
			p->next = new ListNode(dig);
			p = p->next;
		});
		return ln;
	}
	ListNode* ln1 = nullptr;
	ListNode* ln2 = nullptr;
	Solution solution;
};

TEST_F(NO_00002, 0)
{
	Test({ 2, 4, 3 }, { 5, 6, 4 }, { 7, 0, 8 });
}
TEST_F(NO_00002, 1)
{
	Test({ 0 }, { 0 }, { 0 });
}
TEST_F(NO_00002, 2)
{
	Test({ 9, 9, 9, 9, 9, 9, 9 }, { 9, 9, 9, 9 }, { 8, 9, 9, 9, 0, 0, 0, 1 });
}

TEST_F(NO_00002, VALIDATION)
{
	ListNode* p = nullptr;
	ListNode* ln = nullptr;
	p = ln = Build({ 1, 2, 3 });

	ASSERT_EQ(p->val, 1);
	ASSERT_NE(p->next, nullptr);
	p = p->next;
	ASSERT_EQ(p->val, 2);
	ASSERT_NE(p->next, nullptr);
	p = p->next;
	ASSERT_EQ(p->val, 3);
	ASSERT_EQ(p->next, nullptr);

	p = new ListNode(1, new ListNode(2, new ListNode(3)));
	ASSERT_TRUE(Equals(ln, p));

	Delete(ln);
	Delete(p);
}