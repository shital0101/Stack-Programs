/*Write a program to convert an infix expression of the form (a*(b+c)*((d- a)/b)) into its equivalent postfix notation. Consider usual precedence's of operators. Use stack library of stack of characters using static implementation.*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 50
struct stack
{
    char a[MAX];
    int top;
}s;

void init()
{
   s.top=-1;
}

int isfull()
{
    if(s.top==MAX-1)
      return 1;
    else
      return 0;
}

int isempty()
{
   if(s.top==-1)
    return 1;
   else
    return 0;
}

void push(char ch)
{
   if(isfull())
    printf("\nstack is overflow");
   else
   {
     s.top++;
     s.a[s.top]=ch;
   }
}

char pop()
{
   char ch;
   if(isempty())
     printf("\n stack underflow");
   else
    {
      ch=s.a[s.top];
      s.top--;
    }
    return ch;
}

int priority(char ch)
{
    if(ch=='(')
     return 0;
    if(ch=='+'||ch=='-')
      return 1;
    if(ch=='*'||ch=='/')
      return 2;
    if(ch=='$'||ch=='^')
     return 3;
}

int main()
{
    char s1[100],ch;
    int i;
    printf("\n enetr the infix string:");
    scanf("%s",s1);
    init();
    for(i=0;s1[i]!='\0';i++)
    {
       if(isalpha(s1[i]))
        {
           printf("%c",s1[i]);
        }
       else if(s1[i]=='(')
        {
          push(s1[i]);
        }
       else if(s1[i]==')')
        {
           while((ch=pop())!='(')
            {
                printf("%c",ch);
            }
        }
        else
        {
          while(priority(s.a[s.top])>=priority(s1[i]))
             {
                printf("%c",pop());
             }
               push(s1[i]);
        }
     }

       if(!isempty())
       {
          printf("%c",pop());
       }
}
