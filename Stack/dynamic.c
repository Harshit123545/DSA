#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
} *top = NULL;
void push(struct stack **, int);
void pop(struct stack **);
void display(struct stack *r);
int main()
{
    int ch, val;
    while (1)
    {
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. Exit\n");
        printf("4. display\n");
        printf("Enter the choice from user: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter tha data: ");
            scanf("%d", &val);
            push(&top, val);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            exit(1);
        case 4:
            display(top);
            break;
        default:
            printf("\nYou have entered wrong choice");
        }
    }
    return 0;
}
void push(struct stack **top, int new_data)
{
    // allocate a memory for a new node
    struct stack *new_stack = (struct stack *)malloc(sizeof(struct stack));
    // assign the data to new node
    new_stack->data = new_data;
    // set the next of the mew node as tha current head
    new_stack->next = *top;
    // move the head to point to the new node
    *top = new_stack;//*head
}
void pop(struct stack **top)
{
    if (*top== NULL)
    {
        return;
    }
    else
    {
        struct stack *temp = *top;
        *top = (*top)->next;
        printf("\n deleted item is %d\n", temp->data);
        free(temp);
    }
}
void display(struct stack *r)
{
    while (r != NULL)
    {
        printf("%d -> ", r->data);
        r = r->next;
    }
    printf("NULL\n");
}