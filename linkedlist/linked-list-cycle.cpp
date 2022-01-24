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
     bool hasCycle(ListNode *head)
     {
          if (head == NULL || head->next == NULL)
               return false;

          ListNode *fastPtr = head, *slowPtr = head;
          while (fastPtr != NULL && fastPtr->next != NULL && slowPtr != NULL)
          {
               slowPtr = slowPtr->next;
               fastPtr = fastPtr->next->next;
               if (slowPtr == fastPtr)
               {
                    return true;
               }
          }
          return false;
     }
};