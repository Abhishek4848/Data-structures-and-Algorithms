#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *llink;
    struct Node *rlink;
};
typedef struct Node NODE;
void insertbeg(int ele);
void insertend(int ele);
void insertpos(int ele, int pos);
void display();
void reverseDisplay();
int no_of_nodes();

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

int main()
{
    head = NULL;
    int ch  = 1,e,pos;
    printf("0.Exit \n1.Inset at beginning \n2.Insert at end \n3.Insert at specified position \n4.Display \n5.Reverse Display");
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
                insertbeg(e);
            }
            break;
            case 2:
            {
                printf ("\n Enter element to be inserted:");
                scanf ("%d",&e);
                insertend(e);
            }
            break;
            case 3:
            {
                printf ("\n Enter element to be inserted:");
                scanf ("%d",&e);
                printf("\nEnter position to be inserted:");
                scanf("%d",&pos);
                insertpos(e,pos);
            }
            break;
            case 4: display();
            break;
            case 5: reverseDisplay();
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

void insertbeg(int ele)
{
    NODE *new;
    new = getnode(ele);
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        head->llink = new;
        new->rlink = head;
        head = new;
    } 
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

void insertpos(int ele, int pos)
{
    NODE *new,*aux,*next;
    new = getnode(ele);
    aux = head;
    int i;
    if (pos == 0)
    {
        insertbeg(ele);
    }
    else if(pos == no_of_nodes())
    {
        insertend(ele);
    }
    else
    {
        for (i = 1; i<pos; i++)
        {
            aux = aux->rlink;
        }
        next = aux->rlink;
        aux->rlink = new;
        new->llink = aux;
        new->rlink = next;
        next->llink = new;
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

void reverseDisplay()
{
    NODE *aux;
    aux = head;
    while(aux->rlink != NULL)
    {
        aux = aux->rlink;
    }
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->llink;
    }
    printf("\n");
}



