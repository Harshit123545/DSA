#include <stdio.h>
#include <stdlib.h>

struct queue {
    int data;
    struct queue *next;
} *front = NULL, *rear = NULL;

void insertion(struct queue **rear, struct queue **front, int new_data);
void deletion(struct queue **front);
void display(struct queue *front);

int main() {
    int ch, val;
    while (1) {
        printf("\nMenu\n1. Insert  into  queue\n2. Delete into  queue\n3. Display the queue \n4.exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter Data: \n");
                scanf("%d", &val);
                insertion(&rear, &front, val);
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
                printf("Wrong Choice\n");
                break;
        }
    }
    return 0;
}

void insertion(struct queue **rear, struct queue **front, int new_data) {
    struct queue *new_node = (struct queue *)malloc(sizeof(struct queue));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*rear == NULL) {
        *rear = new_node;
        *front = new_node;
        (*rear)->next = *rear;
    } else {
        new_node->next = (*rear)->next;
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

void deletion(struct queue **front) {
    if (*front == NULL) {
        printf("Queue is empty, cannot delete.\n");
        return;
    }

    struct queue *temp = *front;
    if (*front == rear) { // Only one element
        *front = NULL;
        rear = NULL;
    } else {
        *front = (*front)->next;
        rear->next = *front;
    }
    printf("Deleted item is %d\n", temp->data);
    free(temp);
}

void display(struct queue *front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct queue *temp = front;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("front\n");
}