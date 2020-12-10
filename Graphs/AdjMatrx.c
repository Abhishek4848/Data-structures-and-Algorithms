#include<stdio.h>
#define maxnodes 50

void init_graph(int [][maxnodes],int);
void create_graph(int [][maxnodes]);
void display(int [][maxnodes],int);

void init_graph(int adjmat[][maxnodes],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            adjmat[i][j] = 0;
        }
    }
}

void create_graph(int adjmat[][maxnodes])
{
    int i, j;
    while(1)
    {
        printf("Enter node:");
        scanf("%d",&i);
        printf("Enter its Adjacent node:");
        scanf("%d",&j);
        if(i == 0 && j == 0)
        {
            break;
        }
        adjmat[i][j] = 1;
    }
}

void display(int adjmat[][maxnodes],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%3d",adjmat[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int ch = 1, n;
    int adjmat[maxnodes][maxnodes];
    printf("1. Create Graph \n2. Display \n3. Exit");
    while(ch != 0)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter size of matrix:");
                    scanf("%d",&n);
                    init_graph(adjmat, n);
                    create_graph(adjmat);
                    break;
            case 2: display(adjmat,n);
                    break;
            case 3: exit(0);
                    break;
            default: printf("Invalid choice"); 
        }
    }
}   