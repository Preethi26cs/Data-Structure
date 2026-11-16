#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue() {
    int x;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Queue overflow (Memory allocation failed)\n");
        return;
    }

    printf("Enter the element: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = NULL;

    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    struct node* temp;

    if (front == NULL) {
        printf("Queue underflow\n");
    } else {
        temp = front;
        printf("Deleted element = %d\n", front->data);
        front = front->next;

        // Reset rear if the queue is now empty
        if (front == NULL) {
            rear = NULL;
        }

        free(temp); // Free the old front node
    }
}

void display() {
    struct node* temp;

    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        temp = front;
        printf("Elements are:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
