#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};
struct node*top=NULL;
void push() {
    int x;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Stack overflow (Memory allocation failed)\n");
        return;
    }

    printf("Enter the element:\n");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = top;
    top = newnode;
    printf("Inserted Element\n");
}

void pop() {
    struct node* temp;
    if (top == NULL) {
        printf("Stack underflow\n");
    } else {
        temp = top;
        printf("Deleted element = %d\n", top->data);
        top = top->next;
        free(temp); // Free temp, not top
    }
}

void display() {
    struct node* temp;
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        temp = top;
        printf("Elements are:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice;
    while (1) { // Loop keeps the menu active until the user chooses Exit
        printf("\n1. Push  2. Pop  3. Display  4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}
