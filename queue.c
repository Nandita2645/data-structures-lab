#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int queue[MAX];
int front=-1;
int rear=-1;

void insert()
{
    int item;
    if(rear==MAX-1)
    printf("queue is full\n");
    else
    {
        if(front==-1)
            front=0;
            printf("insert the element:");
            scanf("%d",&item);
            rear=rear+1;
            queue[rear]=item;
    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)
    printf("queue is empty\n");
    else
    {
        printf("queue is: \n");
        for(i=front;i<=rear;i++)
        printf("%d\n",queue[i]);
        printf("\n");
    }
}
void delete()
{
    if(front==-1 || front>rear)
    {
        printf("queue underflow\n");
        return;
    }
    else
    {
        printf("deleted element is: %d\n",queue[front]);
        front=front+1;
    }
}
void main()
{
   int choice;
   while(1)
   {
       printf(" 1.insert 2.display 3.delete 4.exit\n");
       printf("enter your choice: \n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:insert();
           break;
           case 2:display();
           break;
           case 3:delete();
           break;
           case 4:exit(1);
           default:
           printf("invalid choice\n");
       }
   }
}
