#include <iostream>
using namespace std;

int countSetBits(int num)
{
    int mask = 1, count = 0;
    while (mask)
    {
        if (mask & num)
            count++;
        mask = mask << 1;
    }
    return count;
}