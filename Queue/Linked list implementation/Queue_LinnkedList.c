#include <stdio.h>
#include <stdlib.h>

struct node
{
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

// Queue operations should take constant time
// If we traverse the queue using single pointer time complexity = O(n)[Directly proportional to number of elements]
// Using double pointers enqueue and dequeue take constant time O(1) [No traversal required]
NODE *front = NULL, *rear = NULL;

void enqueue(int ele)
{
    NODE *new = getnode(ele);
    if (front == NULL && rear == NULL)
    {
       front = rear = new; 
       return;
    }
    rear->link = new;
    rear = new;
}

void dequeue()
{
    NODE *temp = front;
    if(front == NULL && rear ==  NULL) return;
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->link;
    }
    free(temp);
}

int peek()
{
    return front->data;
}

void display()
{
    NODE *aux = front;
    if(front == NULL) printf("Empty Queue ");
    printf("Queue: ");
    while (aux != NULL)
    {
        printf("%d ",aux->data);
        aux = aux->link;
    }
    printf("\n");
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
                enqueue(ele);
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

