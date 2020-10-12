#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *llink;
    struct Node *rlink;
};
typedef struct Node NODE;

NODE *getnode(int ele)
{
    NODE *newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->llink = NULL;
    newnode->rlink = NULL;
    return newnode;
}

NODE *head;

void insertend(int ele);
void deletebeg();
void deleteend();
void deletepos(int pos);
void display();

int main()
{
    head = NULL;
    int ch  = 1,e,pos;
    printf("0.Exit \n1.Insert at end \n2.Delete Beginning \n3.Delete End \n4.Delete at given position \n5.Display");
    while(ch !=0)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: exit(0);
            break;
            case 1:
            {
                printf ("\n Enter element to be inserted:");
                scanf ("%d",&e);
                insertend(e);
            }
            break;
            case 2: deletebeg();
            break;
            case 3: deleteend();
            break;
            case 4:
            {
                printf("\nEnter position to be deleted:");
                scanf("%d",&pos);
                deletepos(pos);
            }
            break;
            case 5: display();
            break;
            default: printf("\n Invalid choice");
            break;
        }
    }
    return 0;
}

int no_of_nodes()
{
    int c = 0;
    NODE *aux = head;
    if (head == NULL)
    {
        c = 0;
    }
    else
    {
        while (aux != NULL)
        {
            c++;
            aux = aux->rlink;
        }
    }
    return c;
}

void insertend(int ele)
{
    NODE *new,*aux;
    new = getnode(ele);
    aux = head;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (aux->rlink != NULL)
        {
            aux = aux->rlink;
        }
        aux->rlink = new;
        new->llink = aux;
    }   
}

void deletebeg()
{
    NODE *temp;
    temp = head;
    if (head == NULL)
    {
        printf("\nEMPTY");
    }
    else
    {
        head = head->rlink;
        head ->llink = NULL;
        free(temp);
    }  
}

void display()
{
    NODE *aux;
    aux = head;
    if (head == NULL)
    {
        printf("\nEMPTY");
    }
    else
    {
        while (aux != NULL)
        {
            printf("%d ",aux->data);
            aux = aux->rlink;
        }
        printf("\n");
    }
}

void deleteend()
{
    NODE *aux,*prev;
    aux = head;
    if (head == NULL)
    {
        printf("\nEMPTY");
    }
    while(aux->rlink != NULL)
    {
        aux = aux->rlink;
    }
    prev = aux->llink;
    prev->rlink = NULL;
    free(aux);
}

void deletepos(int pos)
{
    NODE *next,*prev,*aux;
    aux = head;
    int i;
    if (head == NULL)
    {
        printf("\nEMPTY");
    }
    else
    {
        for (i = 0; i<pos; i++)
        {
            aux = aux->rlink;
        }
        next = aux->rlink;
        prev = aux->llink;
        prev ->rlink = next;
        next->llink = prev;
        free(aux);
    }
}