#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;

} *head = NULL;
void insert_at_begin(struct node **, int);
void display(struct node *);
void insert_at_end(struct node **, int);
void delete_begin(struct node **);
void delete_last(struct node **);
 void insert_at_specific(struct node **, int, int);
 void delete_at_specific(struct node **, int);
int main()
{
    int ch, val, pos;
    while (1)
    {
        printf("1. Insert at begin\n");
        printf("2. Insert at End\n");
        printf("3. count\n");
        printf("4. Delete_begin\n");
        printf("5. Display\n");
        printf("6. Delete_last\n");
        printf("7. Insert_at_a_specific\n");
        printf("8. Delete_at_a_specific\n");
        printf("9. search the element\n");
        printf("10. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter tha data: ");
            scanf("%d", &val);
            insert_at_begin(&head, val);
            break;
        case 2:
            printf("\nEnter tha data: ");
            scanf("%d", &val);
            insert_at_end(&head, val);
            break;
            // case 3:
            //     count(head);
            //     break;
        case 4:
            delete_begin(&head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            delete_last(&head);
            break;
        case 7:
            printf("\nEnter a data and position: ");
            int data;
            int position;
            scanf("%d%d", &data, &position);
            insert_at_specific(&head, data, position);
            break;
        case 8:
            printf("\nEnter the position: ");

            scanf("%d", &pos);
            delete_at_specific(&head, pos);
            break;
        // case 9:
        //     printf("\nenter the element to search:");
        //     scanf("%d", &val);
        //     search(head, val);
        //     break;
        case 10:
            exit(1);
        default:
            printf("\nYou have entered wrong choice");
        }
    }
    return 0;
}
void insert_at_begin(struct node **head_ref, int new_data)
{
    // allocate a memory for a new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    // assign the data to new node
    new_node->data = new_data;
    new_node->prev = NULL;

    // set the next of the mew node as tha current head
    new_node->next = *head_ref;
    if (*head_ref != NULL)
    {
        (*head_ref)->prev = new_node;
    }
    // move the head to point to the new node
    *head_ref = new_node;
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
void insert_at_end(struct node **head_ref, int new_data)
{

    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = new_data;

    // if the list is empty ,make the new node as the head
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    // traverse to last node
    struct node *temp = *head_ref;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // link the new node to the last node's next pointer
    temp->next = new_node;
    new_node->prev = temp;
}
void delete_last(struct node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("Linkedlist is empty\n");
        return;
    }
    struct node *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    if (last->prev != NULL)
    {
        last->prev->next = NULL;
    }
    else
    {
        *head_ref = NULL;
    }
    printf("\ndeleted item %d\n", (last->data));
    free(last);
}
void delete_begin(struct node **head_ref)
{
    if (*head_ref == NULL)
    {
        return;
    }
    struct node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    printf("\n Deleted item is %d\n", temp->data);
    (*head_ref)->prev = NULL;
    free(temp);
}
void insert_at_specific(struct node** head_ref,int new_data,int pos)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node*temp=*head_ref;
    new_node->data=new_data;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(pos==0)
    {
        new_node->next=temp;
        temp=new_node;
        temp->prev=NULL;
        return;
    }
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;

    }
    if (temp == NULL)
    {
        printf("invalid position. Inserting at the end.\n");
        temp = *head_ref;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev=temp;
    }
    else
    {
        // insert the new noode at the specified position
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev=temp;
        (temp->next)->prev=new_node;
    }
}
void delete_at_specific(struct node** head_ref,int pos)
{
        // if linked list is empty
    if (*head_ref == NULL)
    {
        return;
    }
    // store head node
    struct node *temp = *head_ref;
    // if the head needs to be removed
    if (pos == 0)
    {
        *head_ref == temp->next;
        (*head_ref)->prev=NULL;
        temp->next=NULL;

        // changed head
        printf("\n Deleted item is %d\n ", temp->data);
        free(temp); // free old head
        return;
    }
    // find previous node of node to be deleted
    for (int i = 0; temp != NULL && i < pos - 1; ++i)
    {
        temp = temp->next;
    }
    // if position is more than the number of nodes
    if (temp == NULL || (temp->next) == NULL)
    {
        return;
    }
    // node temp->next is the node to be deleted
    // store pointer to next of the node be deleted
    struct node * next = temp->next->next;
    printf("\nDeleted item is %d \n ", (temp->next)->data);
    // unlike the node from linked list
    struct node* flag=temp->next;
    temp->next=flag->next;
    (flag->next)->prev=temp;
    flag->next=NULL;
    flag->prev=NULL;
    free(flag);
}