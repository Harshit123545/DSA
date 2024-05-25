#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;
void insert_at_begin(struct node **, int);
void display(struct node *);
void insert_at_end(struct node **, int);
void delete_begin(struct node **);
void count(struct node *);
void delete_last(struct node **);
void insert_at_specific(struct node **, int, int);
void delete_at_specific(struct node **, int);
void search(struct node* r,int);
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
        printf("Enter the choice from user: ");
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
        case 3:
            count(head);
            break;
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
        case 9:
            printf("\nenter the element to search:");
            scanf("%d",&val);
            search(head,val);
            break;
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
    // set the next of the mew node as tha current head
    new_node->next = *head_ref;
    // move the head to point to the new node
    *head_ref = new_node;//*head
}
void insert_at_end(struct node **head_ref, int new_data)
{

    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = new_data;
    // if the list is empty ,make the new node as the head
    new_node->next = NULL;
    if (*head_ref == NULL)
    {

        *head_ref = new_node;
    }
    else
    {
        // traverse to last node
        struct node *temp = *head_ref;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // link the new node to the last node's next pointer
        temp->next = new_node;
    }
}
void count(struct node *r)
{
    int count = 0;
    while (r != NULL)
    {
        count++;
        r = r->next;
    }
    printf("The count=%d\n", count);
}
void delete_begin(struct node **head_ref)
{
    if (*head_ref == NULL)
    {
        return;
    }
    else
    {
        struct node *temp = *head_ref;
        *head_ref = (*head_ref)->next;
        printf("\n deleted item is %d\n", temp->data);
        free(temp);
    }
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
void delete_last(struct node **head_ref)
{
    if (*head_ref == NULL)
    {
        return;
    }
    // if only one node is present
    if ((*head_ref)->next == NULL)
    {
        printf("\n DEleted item is %d\n", (*head_ref)->data);
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    struct node *temp = *head_ref;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    // delete last node node and adjust the next pointer of the second_to_last
    printf("\ndelete item is %d\n",(temp->next->data));
    free(temp->next);
    temp->next = NULL;
}
void insert_at_specific(struct node **head_ref, int new_data, int position)
{
    // creata a new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    // if position is 0 insert at begining
    if (position == 0)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    // traverse the list to find the node just before the position
    struct node *current = *head_ref;
    for (int i = 0; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }
    // if position is greater then the length of the list ,insert at the end
    if (current == NULL)
    {
        printf("invalid position. Inserting at the end.\n");
        current = *head_ref;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    else
    {
        // insert the new noode at the specified position
        new_node->next = current->next;
        current->next = new_node;
    }
}
void delete_at_specific(struct node **head_ref, int pos)
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
    if (temp == NULL || temp->next == NULL)
    {
        return;
    }
    // node temp->next is the node to be deleted
    // store pointer to next of the node be deleted
    struct node *next = temp->next->next;
    printf("\nDeleted item is %d \n ", (temp->next)->data);
    // unlike the node from linked list
    free(temp->next);
    temp->next = next;
}
void search(struct node* r,int key)
{   int f=0;
    while (r!=NULL)
    {
        if(r->data==key){
            printf("Data is found\n");
            f=1;
            break;
        }
        r=r->next;
    }
    if(f==0){
        printf("Data not found\n");
    }
}