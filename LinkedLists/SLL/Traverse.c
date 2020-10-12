#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

typedef struct node NODE;

NODE* getnode(int ele)
{
    NODE* newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->link = NULL;
    return newnode;
}

int main()
{
    int count = 0;
    NODE *first,*second,*third,*aux;
    first = getnode(10);
    second = getnode(20);
    third = getnode(30);

    first->link = second;
    second->link = third;  //first->link->link = third;
    aux = first;
    if (aux == NULL)
    {
        printf("Empty linked list \n");
    }
    while (aux != NULL)
    {
        count++;
        printf("%d \n",aux->data);
        aux = aux->link;
    }
    printf("No. of nodes = %d",count);
    return 0;
}