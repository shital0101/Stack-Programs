/*Write a program that copies the contents of one stack into another. Use stack library to perform basic stack operations. The order of two stacks must be identical. (Hint: Use a temporary stack to preserve the order).*/

#include<stdio.h>
#include<stdlib.h>
char s[20];
int top;

void init()
{
   top=-1;
}

int isfull()
{
   if(top==19)
    return 1;
   else
    return 0;
}

int isempty()
{
   if(top==-1)
     return 1;
   else
     return 0;
}

void push(char ch)
{
   if(isfull())
    printf("\n stack is overflow:");
   else
    {
       top++;
       s[top]=ch;
    }
}

char pop()
{
    char ch;
    if(isempty())
     printf("\n stack underflow:");
    else
     {
       ch=s[top];
        top--;
     }
       return ch;
}

int main()
{
    int i,k=0;
    char temp[20];
    init();
    char s1[20];
    printf("\n enter the string:");
    scanf("%s",s1);
    for(i=0;s1[i]!='\0';i++)
    {
        push(s1[i]);
    }

     while(!isempty())
     {
         temp[k]=pop();
          k++;
     }
    temp[k]='\0';

     printf("\n coiped stack:");
     for(i=0;temp[i]!='\0';i++)
     {
         push(temp[i]);
     }

     while(!isempty())
     {
        printf("%c",pop());
     }
}
