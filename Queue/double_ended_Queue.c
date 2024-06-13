#include <stdio.h>

#define size 5

int q[size];
int front = -1;
int rear = -1;

void insertion(int val) {
    if (rear == size ) {
        printf("Overflow\n");
    } else if (rear == -1) {
        front = 0;
        rear++;
        q[rear] = val;
    } else {
        rear++;
        q[rear] = val;
    }
}

void deletion() {
    if (front == -1 && rear == -1) {
        printf("Underflow\n");
    } else if (front == rear) {
        printf("%d\n", q[front]);
        front = -1;
        rear = -1;
    } else {
        printf("%d\n", q[front]);
        front++;
    }
}

void insert_front(int val) {
    if (rear == size - 1) {
        printf("Overflow: \n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        q[front] = val;
    } else {
        front--;
        if (front == 0) {
            printf("overflow: \n");
        }
        q[front] = val;
    }
}

void delete_rear() {
    if (rear == -1) {
        printf("Underflow: \n");
    } else if (front == rear) {
        printf("delete item from rear: %d\n", q[rear]);
        front = -1;
        rear = -1;
    } else {
        printf("delete item from rear: %d\n", q[rear]);
        rear--;
        if (rear == 0) {
            printf("overflow");
        }
    }
}

void display() {
    int i = front;
    if(front == -1){
        printf("the queue is empty\n");
        return ;
    }
    while (i <= rear) {
        printf("%d ", q[i]);
        i++;
    }
    printf("\n");
}

int main(){
    int ch,val;
    while(1){
        printf("1.Insert At Begin\n2.delete \n3.display \n4.insert_front \n5.delete_rear");
        printf("enter the number here : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter the data: ");scanf("%d",&val);
                    insertion(val);break;
            
            case 2: deletion();break;

            case 3: display();break;

            case 4: printf("\nEnter the data: ");scanf("%d",&val);
                    insert_front(val);break;
            
            case 5: delete_rear();break;

            default: printf("\nYou have Entered wrong choice");
            }
            }
            }