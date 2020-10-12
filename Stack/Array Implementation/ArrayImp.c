#include <stdio.h>
#include <stdbool.h>
# define MAX_SIZE 100
int arr[MAX_SIZE];
int top = -1;

void push(int x)
{
    if(arr[top] == MAX_SIZE-1)
    {
        printf("\nStackoverflow");
        return;
    }
    arr[++top] = x;
}

void pop()
{
    if(top == -1)
    {
        printf("Empty Stack\n");
        return;
    }
    top--;
}

int topEle()
{
    return(arr[top]);
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

void display()
{
    printf("\n Stack:");
    for (int i = 0; i<=top; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int ch = 1;
    int ele;
    printf("1. Push\n2. Pop \n3. top\n4. isEmpty\n5. display\n6. Exit");
    while (ch != 0)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: {
                printf("\nEnter Element to be pushed:");
                scanf("%d",&ele);
                push(ele);
            }
            break;
            case 2: pop();
            break;
            case 3:printf("\nTop element is: %d",topEle());
            break;
            case 4:printf("%d",isEmpty());
            break;
            case 5: display();
            break;
            case 6: exit(0);
            break;
            default: printf("\n Enter a valid choice !!!");
            break;
        }
    }
}