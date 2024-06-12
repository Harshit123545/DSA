#include<stdio.h>
#include<stdlib.h>
#define SIZE 6
int q[SIZE];
int front=-1;
int rear=-1;
void insertion(int);
void deletion();
void display();

int main()
{ 
    int ch,val;
    while(1)
    {
    printf("\n1. Insert  a element\n");
    printf("2. Delete a element\n");
    printf("3. Display elements of queue\n");
    printf("4.Exit\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("enter the element:");
        scanf("%d",&val);
        insertion(val);
        break;
        case 2:
        deletion();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(1);
        break;
        default:
        printf("wrong input");
        
    }
    
    
}
}
void insertion(int data)

{
if(front==(rear+1)%SIZE)
{
     printf("overflow");
}
else if( rear==-1)
{
     front=0;
    rear++;
    q[rear]=data;
   // printf("entered element:%d\n",    q[rear]);
    
   
}
else
{
    rear=(rear+1)%SIZE;
    q[rear]=data;
  // printf("entered element:%d\n",    q[rear]);
    
}
}
void deletion()
{
    if(rear==-1)
{
     printf("underflow");
}
else if(front==rear)
{
    printf("deleted item:%d\n",q[front]);
    front=-1;
    rear=-1;
}
else
{
      printf("deleted item:%d\n",q[front]);
      front=(front+1)%SIZE;
}
}
void display()
{
    int i=front;
    if(front==-1)
    {
        printf("circular queue is empty");
    }
    else
    {
       while(i!=rear)
       {
           printf("%d\t",q[i]);
           i=(i+1)%SIZE;
       }
        printf("%d\t",q[i]);
    }
}