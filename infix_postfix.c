#include <stdio.h>
#include <conio.h>
#define Max 25
char stack[Max];
int top = -1;
// function to insert an element into a stack
int push(char symbol)
{
    top += 1;
    stack[top] = symbol;
}
// fun to delete a symbol from a stack
char pop()
{
    char k;
    k = stack[top];
    top -= 1;
    return k;
}
// fun to check whether the symbol is operand or not
int isoperand(char symbol)
{
    if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 0 && symbol <= 9))
        return 1;
    else
        return 0;
}
// fun to check whether the symbol is operator or not
int isoperator(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*' || symbol == '^')
        return 1;
    else
        return 0;
}
int precedence(char symbol)
{
    int result;
    switch (symbol)
    {
    case '(':
        result = 0;
        break;
    case '+':
    case '-':
        result = 1;
        break;
    case '/':
    case '*':
        result = 2;
        break;
    }
}
void main()
{
    char infix[Max], postfix[Max];
    char symbol;
    int i, j;
    i = j = 0;
    printf("Enter The Infix Expression:");
    gets(infix);
    push('(');
    while (infix[i] != '\0')
    {
        symbol = infix[i];
        if (isoperand(symbol))
        {
            postfix[j] = symbol;
            j += 1;
        }
        if (symbol == '(')
            push(symbol);
        if (isoperator(symbol))
        { // scanning the operator
            while (precedence(stack[top]) >= precedence(symbol))
            {
                int temp = pop();
                postfix[j] = temp;
                j += 1;
            }
            push(symbol);
        }
        if (symbol == ')')
        {
            while (stack[top] != '(')
            {
                int temp = pop();
                postfix[j] = temp;
                j += 1;
            }
            int temp = pop();
        }
        i = i + 1;
    }
    while (stack[top] != '(')
    {
        int temp = pop();
        postfix[j] = temp;
        j = j + 1;
    }
    postfix[j] = '\0';
    printf("The Postfix expression is:%s",postfix);
    getch();
}