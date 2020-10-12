#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//parenthesis matching
//last unclosed, first closed on traversing a expression from left to right
//if opening parenthesis, push it to stack
//when same closing parenthesis encountered, pop it from the stack
//at the end, if theres no element left in the stack, its a valid expression

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

void push(int ele)
{
    NODE *new = getnode(ele);
    new->link = top;
    top = new;
}

void pop()
{
    NODE *temp;
    if(top == NULL) return;
    temp = top;
    top = top->link;
    free(temp);
}

bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}

int topEle()
{
    if(top == NULL)
    {
        printf("Empty stack");
        return;
    }
    return top->data;
}

bool arePair(char open, char close)
{
    if((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'))
    {
        return true;
    }
    return false;
}

int checkParenthesis(char str[100])
{
    for(int i = 0; i<strlen(str); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (top == NULL || arePair(topEle(),str[i]) == false)
            {
                return 0;
            }
            else
            {
                pop();
            }
        }
    }
    if (isEmpty() == true)
    {
        return 1;
    }
    return 0;
}

int main()
{
    char str[100];
    printf("Enter a expression:");
    gets(str);
    int result = checkParenthesis(str);
    if (result == 0)
    {
        printf("Invalid Epression");
    }
    else if (result == 1)
    {
        printf("Valid Expression");
    }
}



