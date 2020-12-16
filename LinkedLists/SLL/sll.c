#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
typedef struct node NODE;

NODE *getnode(int ele)
{
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->link = NULL;
    return newnode;
}

NODE *head = NULL;

void insertbeg(int ele)
{
    NODE *new = getnode(ele);
    if(head == NULL)
    {
        head = new;
    }
    else
    {
        new->link = head;
        head = new;
    }
}

void insertend(int ele)
{
    NODE *new, *next, *aux = head;
    new = getnode(ele);
    if(head == NULL)
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
}

int length()
{
    NODE *aux = head;
    int count = 0;
    if(head == NULL) return 0;
    else
    {
        while(aux != NULL)
        {
            count++;
            aux = aux->link;
        }
        return count;
    }
    
}

void insertpos(int pos, int ele)
{
    NODE *aux = head, *new, *next;
    new = getnode(ele);
    if(pos == 1) insertbeg(ele);
    else if(pos == length()+1) insertend(ele);
    else
    {
        for(int i = 1; i < pos -1; i++)
        {
            aux = aux->link;
        }
        next = aux->link;
        aux->link = new;
        new->link = next;
    }
}

void deletebeg()
{
    NODE *temp = head;
    if(head == NULL)
    {
        printf("Empty linked list");
    }
    else
    {
        head = head->link;
        free(temp);
    }  
}

void deleteend()
{
    NODE *aux = head, *prev;
    if(head == NULL)
    {
        printf("Empty linked list");
    }
    else
    {
        while(aux->link != NULL)
        {   prev = aux;
            aux = aux->link;
        }
        prev->link = NULL;
        free(aux);
    }
}

void deletepos(int pos)
{
    NODE *aux = head, *prev, *next;
    if(pos == 1) deletebeg();
    else if (pos == length()) deleteend();
    else
    {
        for(int i = 1; i<pos; i++)
        {
            prev = aux;
            aux = aux->link;
        }
        next = aux->link;
        prev->link = next;
        free(aux);
    }
}

void display()
{
    NODE *aux = head;
    while(aux != NULL)
    {
        printf("%d  ",aux->data);
        aux = aux->link;
    }
    printf("\n");
}

int main()
{
    int ch = 0, e;
    int pos;
    printf("1. Insert at beginning \n2. Insert at end \n3. Insert at given position \n4. Delete at beginning \n5. Delete at end \n6. Delete at given position \n7. Display \n8. Exit");
    while(ch != 8)
    {
        printf("\nEnter yout choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element to be inserted: ");
                    scanf("%d",&e);
                    insertbeg(e);
                    break;
            case 2: printf("Enter element to be inserted: ");
                    scanf("%d",&e);
                    insertend(e);
                    break;
            case 3: printf("Enter element to be inserted: ");
                    scanf("%d",&e);
                    printf("Enter position to be inserted: ");
                    scanf("%d",&pos);
                    insertpos(pos, e);
                    break;
            case 4: deletebeg();
                    break;
            case 5: deleteend();
                    break;
            case 6: printf("Enter position to be Deleted: ");
                    scanf("%d",&pos);
                    deletepos(pos);
                    break;
            case 7: display();
                    break;
            case 8: exit(0);
                    break;
            default: printf("\nInvalid choice...");
        }
    }
    return 0;
}