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
// void count(struct node *);
void delete_last(struct node **);
void insert_at_specific(struct node **, int, int);
void delete_at_specific(struct node **, int);
int search(struct node *r, int);
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
        case 9:
            printf("\nenter the element to search:");
            scanf("%d", &val);
            search(head, val);
            break;
        case 10:
            exit(1);
        default:
            printf("\nYou have entered wrong choice");
        }
    }
    return 0;
}
void display(struct node *head)
{
    struct node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

void insert_at_begin(struct node **head_ref, int new_data)
{
    // allocate a memory for a new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    // set data and next pointer of new node
    new_node->data = new_data;

    new_node->next = *head_ref;
    // if list is not empty, find the last node and make it point to new
    if (*head_ref != NULL)
    {
        struct node *temp = *head_ref;
        while (temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    else
    {
        new_node->next = new_node;
    }
    // update head pointer to point to new node
    *head_ref = new_node;
}
void insert_at_end(struct node **head_ref, int new_data)
{
    // allocate a memory for a new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    // set data and next pointer of new node
    new_node->data = new_data;

    new_node->next = *head_ref;
    // if list is not empty, find the last node and make it point to new
    if (*head_ref != NULL)
    {
        struct node *temp = *head_ref;
        while (temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    else
    {
        new_node->next = new_node;
        *head_ref = new_node;
    }
}
void insert_at_specific(struct node **head_ref, int new_data, int position)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (position == 0) {
        insert_at_begin(head_ref, new_data);
        return;
    }
    struct node* current = *head_ref;
    for (int i = 0; i < position - 1 && current->next != *head_ref; i++) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}
void delete_begin(struct node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct node *current = *head_ref;
    struct node *last = *head_ref;
    while (last->next != *head_ref)

    {
        last = last->next;
    }
    // if list contain only one node , set head to null
    if (current->next == *head_ref)
    {
        printf("\n DEleted item is %d\n", current->data);
        free(current);
        *head_ref = NULL;
        return;
    }
    // update last node's next pointer to skip the first node
    last->next = current->next;
    // update head pointer to point to the second node
    *head_ref = current->next;
    // free memory allocated for the first node
    printf("\n DEleted item is %d\n", current->data);
    free(current);
}
void delete_last(struct node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct node *current = *head_ref;
    struct node *prev = NULL;
    while (current->next != *head_ref)

    {
        prev = current;
        current = current->next;
    }
    if (prev == NULL)
    {
        printf("\n DEleted item is %d\n", current->data);
        free(current);
        *head_ref = NULL;
        return;
    }

    // adjust pointers to skip the last node
    prev->next = current->next;
    // free memory allocated for the last node
    printf("\n DEleted item is %d\n", current->data);
    free(current);
}
int search(struct node *head, int target)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }
    struct node *current = head;
    int position = 0;
    do
    {
        if (current->data == target)
        {
            printf("Element %d found at position %d.\n", target, position);
            return 1;
        }
        current = current->next;
        position++;
    } while (current != head);
    printf("Element %d not found in the list.\n", target);
    return 0;
}
void delete_at_specific(struct node **head_ref, int position)
{
    if (*head_ref == NULL)
        return;
    struct node *current = *head_ref;
    struct node *prev = NULL;
    int count = 0;
    if (position == 0)
    {
        delete_begin(head_ref);
        return;
    }
    while (count < position)
    {
        prev = current;
        current = current->next;
        count++;
        if (current == *head_ref)
        {
            printf("Position out of range.\n");
            return;
        }
    }
    prev->next = current->next;
    if (current == *head_ref)
        *head_ref = prev->next;
    printf("\nDeleted item is %d\n", current->data);
    free(current);
}
