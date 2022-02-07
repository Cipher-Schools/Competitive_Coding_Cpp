#include <bits/stdc++.h>
using namespace std;

#define DEFAULT_SIZE 10

template <class T>
class PriorityQueue
{
  private:
    T *Harr;
    int Capacity;
    int Size;

  public:
    PriorityQueue(int Capacity = DEFAULT_SIZE)
    {
        this->Capacity = Capacity;
        this->Size = 0;
        this->Harr = new T[this->Size];
    }

    int Parent(int index)
    {
        return ((index - 1) / 2);
    }

    int LeftChild(int index)
    {
        return ((index * 2) + 1);
    }

    int RightChild(int index)
    {
        return ((index * 2) + 2);
    }

    void MinHeapify(int index)
    {
        int smallest = index;
        int l = this->LeftChild(index);
        int r = this->RightChild(index);
        if (l < this->Size && this->Harr[l] < this->Harr[smallest])
        {
            smallest = l;
        }

        if (r < this->Size && this->Harr[r] < this->Harr[smallest])
        {
            smallest = r;
        }

        if (smallest != index)
        {
            swap(this->Harr[smallest], this->Harr[index]);
            index = smallest;
            this->MinHeapify(index);
        }
    }

    T Top()
    {
        if (this->Size <= 0)
        {
            throw "PriorityQueue underflow!!";
        }
        else
        {
            return this->Harr[0];
        }
    }

    void Push(T data)
    {
        if (this->Size == this->Capacity)
        {
            throw "PriorityQueue overflow!!";
            return;
        }
        else
        {
            int index = this->Size;
            this->Size++;
            this->Harr[index] = data;
            while (index != 0 && (this->Harr[index] < this->Harr[this->Parent(index)]))
            {
                swap(this->Harr[index], this->Harr[this->Parent(index)]);
                index = this->Parent(index);
            }
        }
    }

    void Pop()
    {
        if (this->Size <= 0)
        {
            throw "PriorityQueue underflow!!";
        }
        else if (this->Size == 1)
        {
            this->Size--;
        }
        else
        {
            this->Harr[0] = this->Harr[this->Size - 1];
            this->Size--;
            this->MinHeapify(0);
        }
    }

    int GetSize()
    {
        return this->Size;
    }

    void Display()
    {
        for (int i = 0; i < this->Size; i++)
        {
            cout << this->Harr[i] << " ";
        }

        cout << "\n";
    }
};