#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

typedef struct node NODE;
NODE *insertbeg(NODE *head);
void display(NODE *head);

NODE *getnode(int ele)
{
    NODE *newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->link = NULL;
    return newnode;
}

int main()
{
    NODE *head;
    int ch = 0;
    head = NULL;
    printf("1. Insert Beginning \n2. Display \n3.Exit ");
    while (ch != 3)
    {
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head = insertbeg(head);
            break;
            case 2: display(head);
            break;
            case 3: exit(0);
            default: printf("\n Invalid choice");
        }
    }
    return 0;
}

NODE *insertbeg(NODE *head)
{
    NODE *temp;
    int e;
    printf("Enter the data: ");
    scanf("%d",&e);
    temp = getnode(e);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->link = head;
        head = temp;
    }
    return temp;
}

void display(NODE *head)
{
    NODE *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("Linked list is empty \n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    
}