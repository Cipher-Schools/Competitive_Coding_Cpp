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
    int count(ListNode *node)
    {
        int count = 0;
        while (node != NULL)
        {
            count++;
            node = node->next;
        }
        return count;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;

        int cnt = count(head);
        k = k % cnt;
        if (k == 0)
            return head;

        ListNode *fast = head, *slow = head, *next = NULL;
        while (fast != NULL && k > 0)
        {
            k--;
            fast = fast->next;
        }

        while (fast->next != NULL && slow->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        next = slow->next;
        slow->next = NULL;
        fast->next = head;
        return next;
    }
};