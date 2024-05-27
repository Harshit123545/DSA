// Online C compiler to run C program online
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 2

int top = -1, 
stack[SIZE];
void push();
void pop();
void display();

int main()
{
    int choice;

    while (1)
    {
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element:");
        printf("\n3 Display:");
        printf("\n4 Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

            
        case 2:
            pop();
            break;
            
        case 3:
            display();
            break;
        case 4:
            exit(0);
       
        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push()
{
    int x;

    if (top == SIZE - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        stack[top] = x;
    }
}

void pop()
{
    if (top < 0)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %d", stack[top]);
        top = top-1;
    }
}
void display(){
        if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", stack[i]);
        
    }
}
