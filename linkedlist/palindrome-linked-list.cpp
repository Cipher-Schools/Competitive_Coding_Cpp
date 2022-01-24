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
     bool isPalindrome(ListNode **left, ListNode *right)
     {
          if (right == NULL)
          {
               return true;
          }
          bool isp = isPalindrome(left, right->next);
          if (!isp)
          {
               return false;
          }
          bool isp1 = ((*left)->val == right->val);
          (*left) = (*left)->next;
          return isp1;
     }
     bool isPalindrome(ListNode *head)
     {
          if (head == NULL || head->next == NULL)
               return true;
          ListNode *left = head, *right = head;
          return isPalindrome(&left, right);
     }
};