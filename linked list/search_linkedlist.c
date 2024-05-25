#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head= NULL;
void insert_at_beg(struct node**, int);
void insert_at_end1(struct node*, int);
void display(struct node*);
void count(struct node*);
void insert_at_end2(struct node**, int);
void delete_begin(struct node** head_ref);
void delete_last(struct node** head_ref);
void insert_at_specific(struct node**, int , int);
void delete_at_specific(struct node**, int);
void search (struct node* r, int key);
int main()
{
    int position;
	int choice, val;
    while(1)
{
    printf("Enter your choice :  \n");
    printf("1. Insert at Begin :  \n");
    printf("2. Insert at End1:  \n");
    printf("3. Display the List :  \n");
    printf("4. Count elements in the List :  \n");
    printf("5. Insert at End2:  \n");
    printf("6. Delete Begin\n");
    printf("7. Delete End\n");
    printf("8. Insert At Specific\n");
    printf("9. Delete At Specific\n");
    printf("10. Search\n");
    
    printf("11. Exit :  \n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter the data");
        scanf("%d",&val);
        insert_at_beg(&head,val);
        break;
    case 2:
        printf("Enter the data");
        scanf("%d",&val);
        insert_at_end1(head,val);
        break;
    case 3:
        display(head);
        break;
    case 4:
        count(head);
        break;
    case 5: 
        printf("Enter the data");
        scanf("%d",&val);
        insert_at_end2(&head,val); 
	case 6: 
        delete_begin(&head);
	case 7:
		delete_last(&head);
	case 8:
		printf("Enter the position  and data");
		scanf("%d", &position);
		scanf("%d",&val);
		insert_at_specific(&head,val,position);
        break;
    case 9:
    	printf("Enter the position");
		scanf("%d",&val);
    	delete_at_specific(&head,val);
    case 10:
    	printf("Enter the search");
    	scanf("%d", &val);
    	search(head, val);
  	case 11:
        exit(1);
    default:
        printf("\nWrong Choice");
        break;
    }
}
return 0;
}
void insert_at_beg(struct node** head_ref, int new_data )
{
    struct node* new_node= (struct node*)malloc(sizeof(struct node)); // Allocate memory for new node
    new_node->data= new_data; // assign the data to new node
    new_node->next= *head_ref;  // set next of thr new node as current head
    *head_ref= new_node; // temp head 
}

void insert_at_end1(struct node* head_ref, int new_data )
{
    struct node* new_node= (struct node*)malloc(sizeof(struct node)); // Allocate memory for new node
    new_node->data= new_data; // assign the data to new node
    new_node->next= NULL;  // set next of thr new node as current head
    if (head==NULL)
        { head=new_node; }
    else
    {
        struct node *temp= head_ref;
        while (temp->next!=NULL) { temp=temp->next ;}
        temp->next=new_node;
    }    
}

void display(struct node* r)
{
    while(r!=NULL)
    { printf("%d ->", r->data); r=r->next; }
    printf("NULL \n");
}
void count(struct node* r)
{   int count=0;
    while(r!=NULL)
    { count=count+1; r=r->next; }
    printf("Total count of elements\n=%d",count);
}

void insert_at_end2(struct node** head_ref, int new_data )
{
    struct node* new_node= (struct node*)malloc(sizeof(struct node)); // Allocate memory for new node
    new_node->data= new_data; // assign the data to new node
    new_node->next= NULL;  // set next of thr new node as current head
    if (*head_ref==NULL)
        { *head_ref=new_node; }
    else
    {
        struct node *temp= *head_ref;
        while (temp->next!=NULL) { temp=temp->next ;}
        temp->next=new_node;
    }    
}

void delete_begin(struct node** head_ref)  
{
	if (*head_ref == NULL)
	return;
	struct node* temp = *head_ref;
	*head_ref = (*head_ref)->next;
	printf("\n deleted item is %d\n", temp->data);
	free (temp);
}

void delete_last(struct node** head_ref)
{
	if (*head_ref == NULL)
	return;
	//if only one node is present
	if ((*head_ref)->next == NULL)
	{
		printf("\nDeleted item is %d\n", (*head_ref)->data);
		free(*head_ref);
		*head_ref = NULL;
		return;
		
	}
	struct node* temp = *head_ref;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	//delete last node and adjust the next pointer of the second to last 
	printf("\n Deleted item is%d\n", (temp->next)->data);
	free (temp->next);
	temp ->next = NULL;
}

void insert_at_specific(struct node** head_ref, int new_data, int position)
{
   //create a new node 
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    //if position is 0, insert at the beginning
    if (position == 0)
    {
    	new_node->next= *head_ref;
    	*head_ref = new_node;
    	return;
	}  
	//traverse the list to find the node just before the position 
	struct node* current = *head_ref;
	for(int i = 0; i < position-1 && current != NULL; i++)
	{
		current = current->next;
	}
	//if position is greater than the length of the list, insert at the end
	if (current == NULL)
	{
		printf("Invalid position. Inserting at the end.\n");
		current = *head_ref;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
	else
	{
		//insert the new node at the specified position
		new_node->next = current->next;
		current->next = new_node;
	}
}

void delete_at_specific(struct node** head_ref, int position)
{
	//if linked list is empty
	if (*head_ref == NULL)
	{
		printf("linked list is empty");
	}
	return;
	struct node* temp = *head_ref;
	//if the head needs to be removed
	if (position == 0)
	{
		*head_ref = temp->next;  //changed head
		printf("\nDeleted Item is %d\n", temp->data);
		free(temp); //free old head
		return;
	}
	//find previous nodeof the node to be deleted
	for (int i = 0; temp != NULL && i < position-1; ++i)
	temp = temp->next;
	//if position is more than the number of nodes
	if (temp == NULL || temp->next == NULL)
	return;
	//node temp->next is the node to be deleted
	//store pointer to the next of the node to be deleted 
	struct node* next = temp->next->next;
	printf("\nDeleted Item is %d \n", (temp->next)->data);
	//unlike the node from linked list
	free (temp->next);
	temp->next = next;
}

void search (struct node*r, int key)
{
	int f = 0;
	while(r != NULL)
	{
		if (r->data == key)
		{
			printf("Element found\n");
			f =1;
			
			break;
		}
			r = r->next;
	}
	if(f == 0)
	{
		printf("element not�found");
	}
	
}
