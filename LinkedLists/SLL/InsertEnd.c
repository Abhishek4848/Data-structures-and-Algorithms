#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node NODE;
NODE *insertend(NODE *head);
void display(NODE *head);

NODE *getnode(int ele)
{
    NODE *newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->link = NULL;
    return newnode;
}

void main()
{
    NODE* head;
    head = NULL;
    int ch = 0;
    printf("1.Insert End \n2.Display \n3.Exit");
    while (ch != 3)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head = insertend(head);
            break;
            case 2: display(head);
            break;
            case 3: exit(0);
            break;
            default : printf("Invalid Choice");
        }
    }
}

NODE *insertend(NODE *head)
{
    NODE *aux;
    aux = head;
    NODE *new;
    int e;
    printf("\n Enter the data: ");
    scanf("%d",&e);
    new = getnode(e);
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while(aux->link != NULL)
        {
            aux = aux->link;
        }
        aux->link = new;
    }
    return head;
}

void display(NODE *head)
{
    NODE *aux;
    aux = head;
    if (aux == NULL)
    {
        printf("Linkedlist is empty");
    }
    else
    {
        while(aux != NULL)
        {
            printf("%d ",aux->data);
            aux = aux->link;
        }
        printf("\n");
    }
    
}