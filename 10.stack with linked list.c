#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* stackTop = NULL;
void push(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = stackTop;
    stackTop = n;
}
int pop() {
    if (!stackTop) return -1;
    int v = stackTop->data;
    struct Node* temp = stackTop;
    stackTop = stackTop->next;
    free(temp);
    return v;
}
void displayStack() {
    struct Node* t = stackTop;
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}

struct Node* qfront = NULL;
struct Node* qrear = NULL;
void enqueue(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x; n->next = NULL;
    if (!qrear) { qfront = qrear = n; return; }
    qrear->next = n; qrear = n;
}
int dequeue() {
    if (!qfront) return -1;
    int v = qfront->data;
    struct Node* temp = qfront;
    qfront = qfront->next;
    if (!qfront) qrear = NULL;
    free(temp);
    return v;
}
void displayQueue() {
    struct Node* t = qfront;
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}

struct Node* cqfront = NULL;
struct Node* cqrear = NULL;
void cqenqueue(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    if (!cqfront) { cqfront = cqrear = n; n->next = cqfront; return; }
    cqrear->next = n;
    cqrear = n;
    cqrear->next = cqfront;
}
int cqdequeue() {
    if (!cqfront) return -1;
    int v = cqfront->data;
    if (cqfront == cqrear) {
        free(cqfront);
        cqfront = cqrear = NULL;
        return v;
    }
    struct Node* temp = cqfront;
    cqfront = cqfront->next;
    cqrear->next = cqfront;
    free(temp);
    return v;
}
void displayCQueue() {
    if (!cqfront) { printf("Empty\n"); return; }
    struct Node* t = cqfront;
    do { printf("%d ", t->data); t = t->next; }
    while (t != cqfront);
    printf("\n");
}

int main() {
    push(10); push(20); push(30);
    printf("Stack: "); displayStack();
    printf("Popped: %d\n", pop());
    printf("Stack after pop: "); displayStack();

    enqueue(10); enqueue(20); enqueue(30);
    printf("\nQueue: "); displayQueue();
    printf("Dequeued: %d\n", dequeue());
    printf("Queue after dequeue: "); displayQueue();

    cqenqueue(10); cqenqueue(20); cqenqueue(30);
    printf("\nCircular Queue: "); displayCQueue();
    printf("Dequeued: %d\n", cqdequeue());
    printf("After dequeue: "); displayCQueue();
}
