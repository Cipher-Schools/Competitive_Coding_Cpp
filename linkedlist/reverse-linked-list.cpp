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
     ListNode *reverseList(ListNode *head)
     {
          if (head == NULL)
               return head;

          ListNode *curr = head, *next = NULL, *prev = NULL;
          while (curr != NULL)
          {
               next = curr->next;
               curr->next = prev;
               prev = curr;
               curr = next;
          }
          return prev;
     }
};