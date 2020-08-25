#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // code is not finished

        ListNode* ans=new ListNode(0);
        ListNode* last= ans;
        ListNode* firstNotZero = NULL;
        int carry = 0;

        auto digitAdd = [&](int&a,int&b) {
            int digitSum = a + b;
            if (carry)++digitSum;
            last->next = new ListNode(digitSum % 10);
            if (digitSum > 9)
            {
                carry = 1;
                firstNotZero = last->next;
            }
            else {
                carry = 0;
                if (!digitSum)firstNotZero = last;
            }
        };

        for (;l1->next && l2->next;l1=l1->next,l2=l2->next, last = last->next)
            digitAdd(l1->val,l2->val);

        for (; l1->next; l1 = l1->next)
            digitAdd(l1->val, carry);
           
        for (; l2->next; l2 = l2->next)
            digitAdd(l2->val, carry);

        if (!last->val)
            for (auto it=firstNotZero->next, next = it->next; it != NULL; it = next, next = it->next)
                delete it;

        firstNotZero->next = NULL;
        last = ans->next;
        delete ans;
        return last;
    }
};