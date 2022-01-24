#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPowUtil(double x, int n)
    {
        if (n == 0)
            return 1;
        else if (n == 1)
            return x;
        else
        {
            double res = myPowUtil(x, n / 2);
            if (n & 1)
            {
                return x * res * res;
            }
            else
            {
                return res * res;
            }
        }
    }

    double myPow(double x, int n)
    {
        if (x == 1)
        {
            return x;
        }
        else if (x == -1)
        {
            return (n & 1 ? -1 : 1);
        }
        if (n < 0)
        {
            if (n == INT_MIN)
            {
                return 1 / (x * myPowUtil(x, INT_MAX));
            }
            return 1 / myPowUtil(x, -n);
        }
        else
        {
            return myPowUtil(x, n);
        }
    }
};

int main()
{
}