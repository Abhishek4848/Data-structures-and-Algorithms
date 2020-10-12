#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node NODE;
NODE *top = NULL;

NODE *getnode(int ele)
{
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->link = NULL;
    return newnode;
} 

//Linked list implementation of stack
//insertion and deletion (push and pop) always takes place at at the front Of single linked list
// takes constant time O(1)
//If push/pop at rear end, time is diectyly proportional to no. of elements O(n)

void push(int ele)
{
    NODE *new = getnode(ele);
    new->link = top;
    top = new;
}

void pop()
{
    if (top == NULL) return;
    NODE* temp = top;
    top = top->link;
    free(temp);
}

int peek()
{
    if (top == NULL)
    {
        printf("\n Empty Stack");
    }
    return top->data;
}

bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}

void display()
{
    if (top == NULL)
    {
        printf("Stack Empty");
    }
    NODE *aux = top;
    printf("Stack: ");
    while (aux != NULL)
    {   
        printf("%d ",aux->data);
        aux = aux->link;
    }
}

int main()
{
    printf("1.Push \n2. Pop \n3. Peek \n4.isEmpty \n5.Dispaly \n6.Exit");
    int ele, ch = 1;
    while(ch != 0)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:{
                printf("\nEnter element to be pushed:");
                scanf("%d",&ele);
                push(ele);
            }
            break;
            case 2: pop();
            break;
            case 3: printf("\nTop element is: %d",peek());
            break;
            case 4: printf("\n%d",isEmpty());
            break;
            case 5: display();
            break;
            case 6: exit(0);
            break;
            default : printf("\nInvalid choice !!!");
            break;
        }
    }
    return 0;
}