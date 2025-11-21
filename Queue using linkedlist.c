#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL)
        return -1;

    int x = front->data;
    struct node *temp = front;

    front = front->next;
    if (front == NULL)
        rear = NULL;

    free(temp);
    return x;
}

void display() {
    struct node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, i, x;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    display();
    printf("\n");

    printf("%d", dequeue());

    return 0;
}
