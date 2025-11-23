#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = value;
        printf("Pushed: %d\n", value);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else {
        printf("Popped: %d\n", stack[top]);
        top--;
    }
}

void displayStack() {
    if (top == -1)
        printf("Stack is Empty\n");
    else {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int queue[SIZE];
int front = 0, rear = -1, count = 0;

void enqueue(int value) {
    if (count == SIZE)
        printf("Queue Overflow\n");
    else {
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        count++;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    if (count == 0)
        printf("Queue Underflow\n");
    else {
        printf("Dequeued: %d\n", queue[front]);
        front = (front + 1) % SIZE;
        count--;
    }
}

void displayQueue() {
    if (count == 0)
        printf("Queue is Empty\n");
    else {
        printf("Queue: ");
        int i = front;
        for (int c = 0; c < count; c++) {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int cqueue[SIZE];
int cfront = -1, crear = -1;

void cenqueue(int value) {
    if ((cfront == 0 && crear == SIZE - 1) || (crear + 1 == cfront))
        printf("Circular Queue Overflow\n");
    else {
        if (cfront == -1) cfront = 0;
        crear = (crear + 1) % SIZE;
        cqueue[crear] = value;
        printf("C-Enqueued: %d\n", value);
    }
}

void cdequeue() {
    if (cfront == -1)
        printf("Circular Queue Underflow\n");
    else {
        printf("C-Dequeued: %d\n", cqueue[cfront]);
        if (cfront == crear)
            cfront = crear = -1;
        else
            cfront = (cfront + 1) % SIZE;
    }
}

void displayCQueue() {
    if (cfront == -1)
        printf("Circular Queue is Empty\n");
    else {
        printf("Circular Queue: ");
        int i = cfront;
        while (1) {
            printf("%d ", cqueue[i]);
            if (i == crear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    printf("=== STACK OPERATIONS ===\n");
    push(10);
    push(20);
    push(30);
    displayStack();
    pop();
    displayStack();

    printf("\n=== QUEUE OPERATIONS ===\n");
    enqueue(5);
    enqueue(15);
    enqueue(25);
    displayQueue();
    dequeue();
    displayQueue();

    printf("\n=== CIRCULAR QUEUE OPERATIONS ===\n");
    cenqueue(100);
    cenqueue(200);
    cenqueue(300);
    displayCQueue();
    cdequeue();
    displayCQueue();

    return 0;
}
