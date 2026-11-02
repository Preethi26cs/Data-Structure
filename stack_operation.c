#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack [MAX];
int top=-1;
void push();
void pop();
void display();

int main()
{
    while(1){
        printf("Stack menu\n 1.push 2.pop 3.display 4.exit\n Enter your choice");
        int choice;
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Inavalid your choice");
        }
    }
    return 0;
}

void push()
{
    if(top==MAX-1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        int value;
        printf("Enter value to push");
        scanf("%d", &value);
        top++;
        stack[top]=value;
        printf("%d has been pushed value",value);

    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("%d has been stack out",stack[top]);
        top--;

    }
}

void display()
{
    int i;
    if(top==-1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements are:\n");

        for(i=top; i>=0; i--)
            printf("%d\n", stack[i]);
    }
}


