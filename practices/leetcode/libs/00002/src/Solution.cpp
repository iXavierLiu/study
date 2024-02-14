#include "Solution.h"

void deleteNodes(ListNode* n)
{
	ListNode* t;
	while (n)
	{
		t = n;
		n = n->next;
		delete t;
	}
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	// 开头填充0
	ListNode* ans = new ListNode(0);
	ListNode* firstNotZero = NULL;
	ListNode* last = ans;
	int v1, v2;
	for (; l1 || l2; l1 && (l1 = l1->next), l2 && (l2 = l2->next), last = last->next)
	{
		v1 = l1 ? l1->val : 0;
		v2 = l2 ? l2->val : 0;
		last->next = new ListNode(v1 + v2);
	}

	for (auto i = ans->next; i; i = i->next)
	{
		if (i->val > 9)
		{
			i->val -= 10;
			if (!i->next)
				i->next = new ListNode(1);
			else
				++i->next->val;
		}
		if (i->val) firstNotZero = i;
	}
	// 全0
	if (!firstNotZero)
	{
		deleteNodes(ans->next);
		ans->next = 0;
		return ans;
	}
	// 删除尾导0
	deleteNodes(firstNotZero->next);
	firstNotZero->next = 0;
	// 删除开头填充0
	auto t = ans;
	ans = ans->next;
	delete t;
	return ans;
}
