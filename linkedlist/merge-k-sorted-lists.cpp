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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        else
        {
            ListNode *result;
            if (l1->val <= l2->val)
            {
                result = l1;
                result->next = mergeTwoLists(l1->next, l2);
            }
            else
            {
                result = l2;
                result->next = mergeTwoLists(l1, l2->next);
            }

            return result;
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        int last = lists.size() - 1, i, j;
        while (last > 0)
        {
            i = 0;
            j = last;
            while (i < j)
            {
                lists[i] = mergeTwoLists(lists[i], lists[j]);
                i++;
                j--;

                if (i >= j)
                {
                    last = j;
                }
            }
        }
        return lists[0];
    }
};