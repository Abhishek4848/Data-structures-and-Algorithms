#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

typedef struct node NODE;
NODE *insertbeg(NODE *head);
NODE *insertend(NODE *head);
NODE *insertpos(NODE *head,int p);
void display(NODE *head);
int length(NODE *head);

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
    head = NULL;
    int ch = 0;
    int pos;
    printf("1. Insert at beginning \n2. Insert at end \n3. Insert at given position \n4.Display \n5. Exit");
    while(ch != 5)
    {
        printf("\nEnter yout choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head = insertbeg(head);
            break;
            case 2: head = insertend(head);
            break;
            case 3:
            {
                printf("Enter position to be inserted: ");
                scanf("%d",&pos);
                if (pos == 0)
                {
                    head = insertbeg(head);
                }
                else if(pos == length(head))
                {
                    head = insertend(head);
                }
                else
                {
                    head = insertpos(head,pos);
                }
                
            }
            break;
            case 4: display(head);
            break;
            case 5: exit(0);
            break;
            default: printf("\nInvalid choice...");
        }
    }
    return 0;
}

NODE *insertbeg(NODE *head)
{
    NODE* aux,*new;
    aux = head;
    int e;
    printf("Enter element to be inserted:");
    scanf("%d",&e);
    new = getnode(e);
    if(aux == NULL)
    {
        head = new;
    }
    else
    {
        new->link = head;
        head = new;
    }
    return head;
}

NODE *insertend(NODE *head)
{
    NODE *aux,*new;
    aux = head;
    int e;
    printf("Enter element to be inserted:");
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
        aux->link = new;
    }
    return head;
}

int length(NODE *head)
{
    NODE *aux;
    aux = head;
    int count;
    while (aux != NULL)
    {
        count++;
        aux = aux->link;
    }
    return count;
}

void display(NODE *head)
{
    NODE *aux;
    aux = head;
    int count;
    if(head == NULL)
    {
        printf("\nLinked list is empty");
    }
    else
    {
        while (aux != NULL)
        {
            count++;
            printf("Element %d = %d \n ",count,aux->data);
            aux = aux->link;
        }
        printf("\n");
    }
}

NODE *insertpos(NODE *head,int p)
{
    NODE *aux,*new,*next;
    aux = head;
    int e,i;
    printf("\nEnter element to be inserted: ");
    scanf("%d",&e);
    new = getnode(e);
    for(i=1; i<p-1; i++)
    {
        aux = aux->link;
    }
    next = aux->link;
    aux->link = new;
    new->link = next;
    return head;
}