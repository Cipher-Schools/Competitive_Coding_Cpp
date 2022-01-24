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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0, head);
        ListNode *fast = &dummy, *slow = &dummy, *temp;
        for (int i = 0; i < n && fast->next != NULL; i++)
        {
            fast = fast->next;
        }
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        temp = slow->next;
        slow->next = temp->next;
        temp->next = NULL;
        delete temp;

        return dummy.next;
    }
};