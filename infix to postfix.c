#include<stdio.h>
#include<conio.h>
#include<ctype.h>

char stack[1000];
int top=-1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if(top==-1)
        return -1;
    return stack[top--];
}

int pres(char ch) {
    if(ch=='^' || ch =='$')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch == '-')
        return 1;
    else if(ch=='(')
        return 0;
}

int main ()
{
    char str[1000];
    int i=0;
    char ch;
    printf("\n Enter a infix expression : ");
    scanf("%s", str);

    while(str[i]!='\0')
    {
        if(isalnum(str[i]))
            printf("%c", str[i]);
        else if(str[i] == '(')
            push(str[i]);
        else if(str[i] == ')')
        {
            while((ch=pop())!='(')
                printf("%c", ch);
        }
        else
        {
            if(pres(stack[top]) >= pres(str[i]))
                printf("%c", pop());
            push(str[i]);
        }

        i++;
    }

    while(top!=-1)  //  printing the rest of the element
    {
        printf("%c", pop());
    }

    getch();
    return 0;
}
