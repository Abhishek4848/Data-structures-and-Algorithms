#include <stdio.h>
#include<ctype.h>
#define MAX_SIZE 100
int stk[MAX_SIZE];
int top = -1;

void push(int ele)
{
    if (top == MAX_SIZE-1)
    {
        printf("Stack Overflow");
    }
    stk[++top] = ele;
}

void pop()
{
    if (top == -1)
    {
        printf ("Stack Empty");
    }
    top--;
}

int isNum(int operand)
{
    if(operand >=0 && operand <=9)
    {
        return 1;
    }
    return 0;
}

int operation(int operand1, int operand2, char operator)
{
    switch(operator)
    {
        case '+': return(operand1 + operand2);
        break;
        case '-': return(operand1 - operand2);
        break;
        case '*': return(operand1 * operand2);
        break;
        case '/': return(operand1 / operand2);
        break;
    }
}

int main()
{
    char infix[MAX_SIZE], ch;
    int i, operand1, operand2, result;
    printf("Enter Infix Expression:");
    gets(infix);
    printf("\nPostfix expression is: %s",infix);
    while(infix[i] != '\0')
    {
        ch = infix[i];
        if(isNum(ch-'0'))
        {
            push(ch-'0');
        }
        else 
        {
            operand2=stk[top--];
            operand1=stk[top--];
            result = operation(operand1, operand2, ch);
            push(result);
        }
        i++;
    }
    printf("\nResult = %d", result);
}