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
    class compare
    { //comaprator for max-heap priority queue
    public:
        bool operator()(ListNode *first, ListNode *second)
        {
            return first->val > second->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int N = lists.size();
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        for (int i = 0; i < N; i++)
        {
            if (lists[i])
                pq.push(lists[i]);
        }
        ListNode dummy(0);
        ListNode *head = &dummy;
        while (!pq.empty())
        {
            head->next = pq.top();
            pq.pop();
            if (head->next != NULL && head->next->next != NULL)
                pq.push(head->next->next);
            head = head->next;
        }
        return dummy.next;
    }
};