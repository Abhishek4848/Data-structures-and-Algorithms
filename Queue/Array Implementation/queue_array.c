#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 101

int arr[MAX_SIZE];
int front = -1, rear = -1;

bool isEmpty()
{
    return(front == -1 && rear == -1);
}

void enqueu(int ele)
{
    if (rear == MAX_SIZE-1)
    {
        printf("Queue Full !!!");
        return;
    }
    else if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = ele;
}

void dequeue()
{
    if(front == rear)
    {
        front = rear = -1;
    }
    else if (isEmpty())
    {
        printf("Queue empty");
        return;
    }
    else
    {
        front++;
    }  
}

void display()
{
    if (!isEmpty())
    {
        printf("Queue: ");
        for(int i = front; i <= rear; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Empty Queue !!!");
    }
    
}

int peek()
{
    if(!isEmpty())
    {
        return arr[front];
    }
}

int main()
{
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit");
    int ch = 1, ele;
    while(ch != 0)
    {
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:{
                printf("Enter Element to be enqueued: ");
                scanf("%d", &ele);
                enqueu(ele);
            }
            break;
            case 2: dequeue();
            break;
            case 3: printf("Top element is: %d",peek());
            break;
            case 4: display();
            break;
            case 5: exit(0);
            break;
            default: printf("Invalid choice !!!");
            break;
        }
    }
}