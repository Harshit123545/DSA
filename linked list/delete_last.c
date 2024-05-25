#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;
void insert_at_begin(struct node**,int);
void display(struct node*);
void insert_at_end(struct node**,int);
void delete_begin(struct node**);
void count(struct node*);
void delete_last(struct node**);
void insert_at_specific(struct node**,int);
int main()
{
    int ch,val;
    while(1){
        printf("1. Insert at begin\n");
        printf("2. Insert at End\n");
        printf("3. count\n");
        printf("4. delete_begin\n");
        printf("5. delete_last\n");
        printf("6. insert at specific\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        scanf("%d",&ch);
        switch(ch){
            
            case 1: 
            printf("\nEnter tha data:");
            scanf("%d",&val);
            insert_at_begin(&head,val);
            break;
            
            case 2: 
            printf("\nEnter tha data");
            scanf("%d",&val);
            insert_at_end(&head,val);
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
            	
            
            case 8:
            exit(1);
            default:
            printf("\nYou have entered wrong choice");
        }
    }
    return 0;

}
void insert_at_begin(struct node** head_ref, int new_data){
    //allocate a memory for a new node
    struct node* new_node= (struct node*)malloc(sizeof(struct node));
    // assign the data to new node
    new_node->data = new_data;
    //set the next of the mew node as tha current head
    new_node->next=*head_ref;
    //move the head to point to the new node
    *head_ref= new_node;
}
void insert_at_end(struct node** head_ref, int new_data) {
    //allocate a memory for a new node
    struct node* new_node= (struct node*)malloc(sizeof(struct node));
    // assign the data to new node
    new_node->data = new_data;
    new_node->next=NULL;
    // if the list is empty,make the new 
    if (*head_ref == NULL){
        *head_ref = new_node;
    }
    else{

        struct node *temp=*head_ref;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }

}
void count(struct node* r) {
    int count=0;
    while (r!=NULL) {
        count++;
        r= r->next;
    }
    printf("%d",count);
}
void delete_begin(struct node** head_ref){
    if(*head_ref == NULL){
        return;
    }
    else{
        struct node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        printf("\n deleted item is %d\n",temp->data);
        free(temp);
    }

}
void display(struct node* r) {
    while(r!=NULL) {
        printf("%d -> ",r->data);
        r= r->next;
    }
    printf("NULL\n");
}
void delete_last(struct node** head_ref){
    if(*head_ref == NULL){
        return;
    }
    // if only one node is present 
    if ((*head_ref)->next == NULL){
        printf("\n Deleted item is %d\n",(*head_ref)->data);
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    struct node* temp = *head_ref;
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    //Delete last node and adjust the next  pointer of the second-to-last
    printf("\n Deleted item is %d\n",(temp->next)->data);
    free(temp->next);
    temp->next = NULL;
}
