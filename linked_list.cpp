#include <stdio.h>
#include <stdlib.h>

class Node
{
public:
    int value;
    Node *next = nullptr;

    Node(int data)
    {
        value = data;
    }
};

class Link
{
    Node *head, *cur;

public:
    Link(int data)
    {
        head = new Node(data);
    }

    void push_back(int value)
    {
        cur = head;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = new Node(value);
    }
    void push_front(int value)
    {
        cur = head;
        head = new Node(value);
        head->next = cur;
    }
    int pop_front()
    {
        int result;
        cur = head;
        head = head->next;
        result = cur->value;
        delete cur;
        return result;
    }
    int pop_back()
    {
        int result;
        Node *pre;
        cur = head;
        while (cur->next)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = nullptr;
        result = cur->value;
        delete cur;
        return result;
    }
    int pop(int idx)
    {
        int result;
        Node *pre;
        cur = head;
        for (int i = 0; i < idx; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        result = cur->value;
        pre->next = cur->next;
        delete cur;
        return result;
    }

    int index(int idx)
    {
        cur = head;
        for (int i = 0; i < idx; i++)
            cur = cur->next;
        return cur->value;
    }
    int operator[](int idx)
    {
        index(idx);
    }

    void print()
    {
        printf("[ ");
        cur = head;
        while (cur->next)
        {
            printf("%d, ", cur->value);
            cur = cur->next;
        }
        if (cur)
            printf("%d", cur->value);
        printf(" ]");
    }

    void printNode()
    {
        printf("[ ");
        cur = head;
        while (cur->next)
        {
            printf("%d, ", cur);
            cur = cur->next;
        }
        if (cur)
            printf("%d", cur);
        printf(" ]");
    }
};

int main()
{
    Link arr(3);
    arr.push_back(5);
    arr.push_back(7);
    arr.push_front(10);
    arr.print();
    printf("\n %d \n", arr.pop(2));
    arr.print();
    return 0;
}
