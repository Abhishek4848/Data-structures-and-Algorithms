#include<stdio.h>
#include<stdlib.h>
#define max 100
int top=-1;
char a[max];
char str[max];
void push(char ch)
{
    if(top == max-1)
    {
        printf("Stack overflow");
    }
    else
    {
        a[++top] = ch;
    }
}

void pop()
{
    if (top==-1)
    {
        printf("Empty stack");
    }
    else
    {
        top--;
    }
    
}

char topEle()
{
    if(top==-1)
        printf("Empty stack");
    return(a[top]);
}

void reverse(char *a)
{
    int n=0;
    for(int i=0; a[i]!= '\0';i++)
    {
        n++;
    }
    for(int i=0;i<n;i++)
    {
        push(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        a[i]=topEle();
        pop();
    }
}

void main()
{
    printf("Enter String to be rversed:");
    gets(str);
    reverse(str);
    printf("\n The reversed string is:");
    printf("%s",str);
}

