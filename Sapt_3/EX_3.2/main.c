#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;


void enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Coada este plină\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = item;
}


int dequeue() {
    if (front == -1 || front > rear) {
        printf("Coada este goală\n");
        return -1;
    }
    return queue[front++];
}


void display() {
    if (front == -1 || front > rear) {
        printf("Coada este goală\n");
        return;
    }
    printf("Elementele din coadă sunt: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Elementul extras din coadă: %d\n", dequeue());
    display();

    return 0;
}
