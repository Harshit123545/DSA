#include<stdio.h>
#define size 5
int q[size];
int front=-1;
int rear=-1;
int insertion(int val);
int deletion(int val);
int main(){
    int ch,val,pos,data;
     while(1){
        printf("1. Insertion\n");
        printf("2. deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
            printf("\nEnter tha data:");
            scanf("%d",&val);
            insertion(val);
            break;
            case 2:
            deletion(val);
            break;
            
            case 3:
            display(val);
            break;
            case 4:
            exit(1);
            default:
            printf("\nYou have entered wrong choice");
        }
    }
    return 0;


}
int insertion(int val){
    if(rear == size-1){
        printf("Overflow");
    }
    if(rear == -1){
        front=0,rear++;
        q[rear]=val;
    }
    else{
        rear++;
        q[rear]=val;
    }
}
int deletion(int val){
    if(rear==-1){`
        printf("Underflow");
    }
    if(front=rear){
        printf("deleted elements are:%d\n",q[front]);
        front=rear-1;
    }
    else{
        printf(q[front++]);
    }
}
void display(){
  if (front == -1){

    
    printf("\nQ is empty");
    }
  else {
    int i;
    printf("element in the stack are:\n");
    for (i = front; i <= rear; i++){
      printf("%d\n",q[i]);
    }
  printf("\n");
}
}