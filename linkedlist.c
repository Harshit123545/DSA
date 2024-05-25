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
void insert_at_end(struct node*,int);
void count(struct node*);
int main()
{
    int ch,val;
    while(1){
        printf("1. Insert at begin\n");
        printf("2. Insert at End\n");
        printf("3. count\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
            insert_at_end(head,val);
            break;
            case 3:
            count(head);
            break;
            
            case 4:
            display(head);
            break;
            case 5:
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
void insert_at_end(struct node* head_ref, int new_data) {
    //allocate a memory for a new node
    struct node* new_node= (struct node*)malloc(sizeof(struct node));
    // assign the data to new node
    new_node->data = new_data;
    //set the next of the new node as the current head
    new_node->next=NULL;
    if (head==NULL){
        head=new_node;
    }
    else{

        struct node *move =head_ref;
        while(move->next!=NULL){
            move=move->next;
        }
        move->next=new_node;
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
void display(struct node* r) {
    while(r!=NULL) {
        printf("%d -> ",r->data);
        r= r->next;
    }
    printf("NULL\n");
}
