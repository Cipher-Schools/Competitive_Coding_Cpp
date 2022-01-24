#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
        {
            return l1;
        }
        else
        {
        }
        ListNode dummy;
        ListNode *p = l1, *q = l2, *r = &dummy;
        int sum = 0, carry = 0;
        while (p != NULL || q != NULL)
        {
            sum = (p != NULL ? p->val : 0) + (q != NULL ? q->val : 0) + carry;
            carry = sum / 10;
            sum = sum % 10;

            r->next = new ListNode(sum);
            r = r->next;

            if (p != NULL)
            {
                p = p->next;
            }

            if (q != NULL)
            {
                q = q->next;
            }
        }

        if (carry != 0)
        {
            r->next = new ListNode(carry);
        }

        return dummy.next;
    }
};