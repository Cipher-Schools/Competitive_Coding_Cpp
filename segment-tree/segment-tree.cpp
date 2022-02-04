#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int *arr;
    int arrSize;
    
    int *tree;
    int N;

    int getLeftChild(int index)
    {
        return 2 * index + 1;
    }

    int getRightChild(int index)
    {
        return (2 * index) + 2;
    }

    void buildTree(int *arr, int nodeIndex, int start, int end)
    {
        if (start == end)
        {
            this->tree[nodeIndex] = arr[start];
        }
        else
        {
            int mid = start + (end - start) / 2;
            int leftIndex = getLeftChild(nodeIndex), rightIndex = getRightChild(nodeIndex);
            buildTree(arr, leftIndex, start, mid);
            buildTree(arr, rightIndex, mid + 1, end);
            this->tree[nodeIndex] = this->tree[leftIndex] + this->tree[rightIndex];
        }
    }

    void updateRange(int nodeIndex, const int &indexToUpdate, int start, int end, const int &val)
    {
        if (indexToUpdate < start || indexToUpdate > end)
        {
            return;
        }
        this->tree[nodeIndex] += val;
        if (start < end)
        {
            int mid = start + (end - start) / 2;
            if (start <= indexToUpdate && indexToUpdate <= mid)
            {
                // element lies in the left side of tree
                updateRange(getLeftChild(nodeIndex), indexToUpdate, start, mid, val);
            }
            else
            {
                // element lies in the right side of tree
                updateRange(getRightChild(nodeIndex), indexToUpdate, mid + 1, end, val);
            }
        }
    }

    int sum(int nodeIndex, int start, int end, const int &qStart, const int &qEnd)
    {
        if (qStart > end || start > qEnd)
        {
            return 0;
        }
        else if (qStart <= start && end <= qEnd)
        {
            return this->tree[nodeIndex];
        }
        else
        {
            int mid = start + (end - start) / 2;
            int leftIndex = getLeftChild(nodeIndex), rightIndex = getRightChild(nodeIndex);
            return sum(leftIndex, start, mid, qStart, qEnd) + sum(rightIndex, mid + 1, end, qStart, qEnd);
        }
    }

public:
    SegmentTree(int *arr, int arrSize)
    {
        this->arrSize = arrSize;
        this->N = 4 * this->arrSize;
        this->arr = arr;
        this->tree = new int[this->N];
        for (int i = 0; i < this->N; i++)
            this->tree[i] = 0;
        buildTree(arr, 0, 0, this->arrSize - 1);
    }

    void PrintSegmentTree()
    {
        for (int i = 0; i < this->N; i++)
        {
            cout << this->tree[i] << ", ";
        }
        cout << "\n";
    }

    void Update(int indexToUpdate, int delta)
    {
        this->arr[indexToUpdate] += delta;
        updateRange(0, indexToUpdate, 0, this->arrSize - 1, delta);
    }

    int Sum(int qStart, int qEnd)
    {
        return sum(0, 0, this->arrSize - 1, qStart, qEnd);
    }
};
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr, 6);
    st.PrintSegmentTree();
    st.Update(1, 1);
    st.PrintSegmentTree();
    cout << st.Sum(2, 4);
}