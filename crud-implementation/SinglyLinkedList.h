#include <bits/stdc++.h>
using namespace std;

template <class T>
class SLLNode
{
  public:
    T data;
    SLLNode *next;
    SLLNode()
    {
        this->next = NULL;
    }

    SLLNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <class T>
class SinglyLinkedList
{
  private:
    SLLNode<T> *head;
    int size;

  public:
    SinglyLinkedList()
    {
        this->head = NULL;
        this->size = 0;
    }

    void PushFront(T data)
    {
        SLLNode<T> *newNode = new SLLNode<T>(data);
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
    }

    void PushBack(T data)
    {
        SLLNode<T> *newNode = new SLLNode<T>(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            SLLNode<T> *p = this->head;
            while (p->next)
            {
                p = p->next;
            }
            p->next = newNode;
        }
        this->size++;
    }

    void Insert(T data, int position)
    {
        SLLNode<T> *newNode = new SLLNode<T>(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else if (position == 1)
        {
            newNode->next = this->head;
            this->head = newNode;
        }
        else
        {
            int k = 1;
            SLLNode<T> *p = this->head;
            SLLNode<T> *q = p;
            while (k < position && p != NULL)
            {
                q = p;
                p = p->next;
                k++;
            }

            newNode->next = p;
            q->next = newNode;
        }
        this->size++;
    }

    void PopFront()
    {
        if (this->head == NULL)
        {
            throw "Singly linked list empty!!";
        }
        else
        {
            SLLNode<T> *p = this->head;
            this->head = this->head->next;
            delete (p);
            this->size--;
        }
    }

    void PopBack()
    {
        if (this->head == NULL)
        {
            throw "Singly linked list empty!!";
            return;
        }
        else if (this->head->next == NULL)
        {
            SLLNode<T> *p = this->head;
            delete (p);
            this->head = NULL;
        }
        else
        {
            SLLNode<T> *p = this->head;
            SLLNode<T> *q = NULL;
            while (p->next != NULL)
            {
                q = p;
                p = p->next;
            }
            q->next = NULL;
            delete (p);
        }
        this->size--;
    }

    T GetElement(int position)
    {
        if (this->head == NULL)
        {
            throw "Singly linked list empty!!";
        }
        else if (this->size < position)
        {
            throw "Given position doesnot exist!!";
        }
        else
        {
            SLLNode<T> *p = this->head;
            int k = 1;
            while (p && k < position)
            {
                k++;
                p = p->next;
            }
            return p->data;
        }
    }

    void Remove(int position)
    {
        if (this->head == NULL)
        {
            throw "Singly linked list empty!!";
            return;
        }
        else if (this->size < position)
        {
            throw "Given position doesnot exist!!";
            return;
        }
        else if (position == 1)
        {
            SLLNode<T> *p = this->head;
            this->head = this->head->next;
            delete (p);
        }
        else
        {
            SLLNode<T> *p = this->head;
            SLLNode<T> *q = this->head;
            int k = 1;
            while (p && k < position)
            {
                q = p;
                p = p->next;
                k++;
            }
            q->next = p->next;
            delete (p);
        }
        this->size--;
    }

    void DeleteList()
    {
        if (this->head == NULL)
        {
            return;
        }
        else
        {
            SLLNode<T> *p = this->head;
            SLLNode<T> *q = NULL;
            while (p)
            {
                q = p->next;
                delete (p);
                p = q;
            }
        }
        this->head = NULL;
        this->size = 0;
    }

    int Size()
    {
        return this->size;
    }
};