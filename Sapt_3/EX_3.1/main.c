#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;


void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stiva este plină\n");
        return;
    }
    stack[++top] = item;
}


int pop() {
    if (top == -1) {
        printf("Stiva este goală\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("Stiva este goală\n");
        return;
    }
    printf("Elementele din stivă sunt: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}


int main() {
    push(10);
    push(20);
    push(30);
    display();

    printf("Elementul extras din stivă: %d\n", pop());
    display();

    return 0;
}
