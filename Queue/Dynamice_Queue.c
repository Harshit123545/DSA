#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void insertion(struct node **front, struct node **rear, int val)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;

    if (*front == NULL && *rear == NULL)
    {
        *front = new_node;
        *rear = new_node;
    }
    else
    {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

void deletion(struct node **front)
{
    if (*front == NULL)
    {
        return;
    }

    struct node *temp = *front;
    *front = (*front)->next;
    printf("\nDeleted item is %d\n", temp->data);
    free(temp);
}

void display(struct node *r)
{
    while (r != NULL)
    {
        printf("%d -> ", r->data);
        r = r->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch, val;
    while (1)
    {
        printf("1. Insert the element\n2. Delete the element\n3. Display\n4. Exit\n");
        printf("Enter the number here: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &val);
            insertion(&front, &rear, val);
            break;

        case 2:
            deletion(&front);
            break;

        case 3:
            display(front);
            break;

        case 4:
            exit(0);

        default:
            printf("\nYou have entered the wrong choice.\n");
            
        }
    
    }
    return 0;
}