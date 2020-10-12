#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node NODE;
NODE *insertend(NODE *head);
NODE *deletebeg(NODE *head);
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
    NODE *head;
    head =NULL;
    int ch = 0;
    while (ch !=4)
    {
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head = insertend(head);
            break;
            case 2: head = deletebeg(head);
            break;
            case 3: display(head);
            break;
            case 4: exit(0);
            break;
            default: printf("Invalid choice");
        }
    }
}

NODE *insertend(NODE *head)
{
    NODE *aux,*new;
    aux = head;
    int e;
    printf("Enter element to be inserted: ");
    scanf("%d",&e);
    new = getnode(e);
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (aux->link != NULL)
        {
            aux = aux->link;
        }
        aux->link  = new;
    }
    return head;
}

void display(NODE *head)
{
    NODE *aux;
    aux = head;
    int count = 0;
    if (head == NULL)
    {
        printf("\nLinked list is empty");
    }
    else
    {
        while (aux != NULL)
        {   count++;
            printf("Element %d: %d\n",count,aux->data);
            aux = aux->link;
        }
        printf("\n");
    }
}
NODE *deletebeg(NODE *head)
{
    NODE *aux;
    aux = head;
    if (head == NULL)
    {
        printf("\nLinked list is empty");
    }
    else
    {
        head = head->link;
        free(aux);
    }
    return head;
}

