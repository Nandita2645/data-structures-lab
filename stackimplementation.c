#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
void push(int);
void pop();
void display();
int stack[10],top=-1;
void main()
{
    int value,choice;
    while(1)
    {
        printf("\n1)PUSH\n2)POP\n3)DISPLAY\n4)EXIT\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the value to be inserted: \n");
                   scanf("%d",&value);
                   push(value);
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default:printf("error");
        }
    }
}
void push(int value)
{
    if(top==SIZE-1)
    printf("stack is full\n");
    else
    {
        top++;
        stack[top]=value;
        printf("done\n");
    }

}
void pop()
{
    if(top==-1)
    {
        printf("stack is empty\n");
    }
        else
        {
            printf("deleted %d\n",stack[top]);
            top--;
        }
}
void display()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
        else
        {
            int i;
            printf("elements are:\n ");
            for(i=top;i>=0;i--)
            printf("%d\n",stack[i]);
        }
}
