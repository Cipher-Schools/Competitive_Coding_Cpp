// https://leetcode.com/problems/merge-sorted-array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {

        int i = m - 1, j = n - 1, itr = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (A[i] > B[j])
                A[itr--] = A[i--];
            else
                A[itr--] = B[j--];
        }

               while (j >= 0)
            A[itr--] = B[j--];
    }
};

int main()
{
}