#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node NODE;
NODE *a[10];
int count = 0;

NODE *getnode(int ele)
{
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->link = NULL;
    return newnode;
}

NODE *insert_rear(int ele, NODE* first)
{
    NODE *new = getnode(ele), *temp = first;
    if (first == NULL)
    {
        return(new);
    }
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;
    return(first);
}

void read_adj_list(NODE *a[], int n)
{
    int m, ele;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the No. of nodes adjacent to %d: ",i);
        scanf("%d",&m);
        if (m == 0) continue;
        printf("Enter the nodes adjacent to %d: ",i);
        for(int j = 0; j < m; j++)
        {
            scanf("%d",&ele);
            a[i] = insert_rear(ele, a[i]);
        }
    }
}

void print_all(int source, int dest, int visited[10], int path[10])
{
    visited[source] = 1;
    path[count] = source;
    count ++;
    if (source == dest)
    {
        for (int i = 0; i < count; i++)
        {
            printf("%d\t",path[i]);
        }
        printf("\n");
    }
    else
    {
        for (NODE *temp = a[source]; temp != NULL; temp = temp->link)
        {
            if(!visited[temp->data])
            {
                print_all(temp->data, dest,visited, path);
            }
        }
    }
    count--;
    visited[source] = 0;
}

void print_path(int source, int dest, int n)
{
    int visited[10];
    int path[10];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    print_all(source, dest, visited, path);
}

void main()
{
    int source, dest, n;
    printf("Enter the No. of vertices:");
    scanf("%d",&n);
    printf("Enter the adjacency list\n");
    read_adj_list(a,n);
    printf("Enter source and destination vertices: ");
    scanf("%d %d",&source,&dest);
    print_path(source, dest, n);
}