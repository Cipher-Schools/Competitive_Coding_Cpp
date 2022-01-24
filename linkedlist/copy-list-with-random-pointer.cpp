#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *ptr = head, *qtr = NULL;
        while (ptr != NULL)
        {
            qtr = ptr->next;
            Node *newNode = new Node(ptr->val);
            newNode->next = qtr;
            ptr->next = newNode;
            ptr = qtr;
        }

        ptr = head, qtr = head->next;
        while (ptr != NULL && ptr->next != NULL)
        {
            qtr = ptr->next;
            if (ptr->random == NULL)
            {
                qtr->random = NULL;
            }
            else
            {
                qtr->random = ptr->random->next;
            }
            ptr = qtr->next;
        }

        Node *newHead = head->next;
        ptr = head;
        while (ptr != NULL && ptr->next != NULL)
        {
            qtr = ptr->next;
            ptr->next = qtr->next;
            ptr = qtr;
        }
        return newHead;
    }
};