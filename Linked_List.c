
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

void push_front(Node *ptr, int data)
{
    Node *newnode = malloc(sizeof(Node));
    /*
    newnode->value = ptr->value;
    newnode->next = ptr->next;
    ptr->value = data;
    ptr->next = newnode;
    */
newnode->value = data;
newnode->next = ptr;
ptr = newnode;
}

void push_back(Node *ptr, int data)
{
    Node *newnode = malloc(sizeof(Node));
    while (ptr->next)
        ptr = ptr->next;
    newnode->value = data;
    ptr->next = newnode;
    newnode->next = NULL;
}
int pop_front(Node *ptr)
{
    int result;
    result = ptr->value;
    Node *temp = ptr;
    while (ptr->next)
    {
        temp = ptr;
        ptr->value = ptr->next->value;
        ptr = ptr->next;
    }
    temp->next = NULL;
    free(ptr);

    return result;
}

int pop_back(Node *ptr)
{
    Node *temp;
    int result;
    while (ptr->next)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    result = ptr->value;
    free(ptr);
    temp->next = NULL;
    return result;
}

int pop(Node *ptr, int index)
{
    int num;
    Node *temp;
    for (int i = 0; i < index; i++)
        {
            temp=ptr;
            ptr = ptr->next;
        }
    temp->next=ptr->next;
    num = ptr->value;
    free(ptr);
    return num;
}

int index(Node *ptr, int num)
{
    for (int i = 0; i < num; i++)

        ptr = ptr->next;

    return ptr->value;
}

void print(Node *ptr)
{
    Node *temp = malloc(sizeof(Node));
    printf("arr = [");
    printf("%d", ptr->value);
    printf(" ]");
    temp = ptr;
    while (temp->next)
        temp = temp->next;
    while (ptr->next)
    {
        ptr = ptr->next;
        printf("\b\b, ");
        printf("%d", ptr->value);
        printf(" ]");
    }
}

int main()
{
    int a, b, c;
    Node *arr = (Node*)malloc(sizeof(Node));
    arr->value = -1;
    arr->next = NULL;
    for (int i = 1; i < 10; i++)
        push_front(arr, i);
    print(arr);
    return 0;
}
