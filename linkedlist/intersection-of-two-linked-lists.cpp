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
    int count(ListNode *head)
    {
        ListNode *ptr = head;
        int count = 0;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            count++;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *a, ListNode *b, int d)
    {
        ListNode *ptr = a, *qtr = b;
        for (int i = 0; i < d && ptr != NULL; i++)
        {
            ptr = ptr->next;
        }

        while (ptr != NULL && qtr != NULL)
        {
            if (ptr == qtr)
            {
                return ptr;
            }
            ptr = ptr->next;
            qtr = qtr->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        int countA = count(headA);
        int countB = count(headB);

        if (countA <= countB)
        {
            return getIntersectionNode(headB, headA, countB - countA);
        }
        else
        {
            return getIntersectionNode(headA, headB, countA - countB);
        }
    }
};