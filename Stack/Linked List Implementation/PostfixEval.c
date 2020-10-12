#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    if(top == NULL) return;
    NODE *temp = top;
    top = top->link;
    free(temp);
}

int peek()
{
    if(top == NULL)
    {
        printf("Empty Stack");
    }
    return top->data;
}

int isNum(int operand)
{
    if (operand >= 0 && operand <= 9)
    {
        return 1;
    }
    return 0;
}

int eval(int operand1, int operand2, char operator)
{
    switch(operator)
    {
        case '+': return (operand1 + operand2);
        break;
        case '-': return (operand1 - operand2);
        break;
        case '*': return (operand1 * operand2);
        break;
        case '/': return (operand1 / operand2);
        break;
    }
}

//To evaluate postfix expression, traverse from left to right
//vice-versa for prefix

int main()
{
    char postfix[100], ch;
    int i = 0, operand1, operand2, result;
    printf("Enter postfix expression:");
    gets(postfix);
    printf("\nPostfix Expression is: %s",postfix);
    while (postfix[i] != '\0')
    {
        ch = postfix[i];
        if (isNum(ch-'0'))
        {
            push(ch-'0');
        }
        else
        {
            operand2 = peek();
            pop();
            operand1 = peek();
            pop();
            result = eval(operand1, operand2, ch);
            push(result);
        }
        i++;
    }
    printf("\nResult = %d",peek());
    return 0;
}
