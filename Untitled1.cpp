#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	
}*head =NULL;
void insert_at_begin(struct node**,int);
void display(struct node*);
void count(int count);
void insert_at_end(struct node*,int);
int main()
{
	int ch,val1;
	while (1){
		printf("1.insert at begin \n 2. Insert at end \n 3. display \n 4. count \n 5. exit ");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
			printf("\n enter the data");
			scanf("%d",&val1);
			insert_at_begin(&head,val1);break;
			case 2: 
			printf("\n enter the data");
			scanf("%d",&val1);
			insert_at_end(head,val1);break;
			case 3: 
			display(head); break;
			case 4: 
			count(head);
			default: printf("\n you have enter wrong choice");
			
		}
	}
	return 0;
}
void insert_at_begin(struct node** head_ref,int new_data){
	//allocate memory for a  new node
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	// assign the data to the new node
	new_node->data = new_data;
	//set tge next of the new node as the currnt head
	new_node->next = *head_ref;
	// move the head to point to the new node
	*head_ref= new_node;
}
void insert_at_end(struct node* head_ref,int new_data){
	// allocate memory for a new node
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	// assign the data to the new node
	new_node->data =new_data;
	//set the next of the new node as the current head
	new_node->next = NULL;
	    if (head=NULL){head=new_node;}
	    else{
	    	struct node *move=head_ref;
	    	while(move->next!=NULL){move=move->next;}
	    	
		}
}
void display(struct node* r){
	while(r!=NULL){
		printf("%d ->",r->data);
		r=r->next;
	}
	
}
