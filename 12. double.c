#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
} Node;

Node *head = NULL;

void insertEnd(int x) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

void deleteNode(int x) {
    Node *temp = head;

    if (temp == NULL) return;

    if (temp->data == x) {
        head = temp->next;
        if (head) head->prev = NULL;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != x)
        temp = temp->next;

    if (temp == NULL) return;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

void display() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {

    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    printf("list = ");
    display();

    insertEnd(70);
    printf("\nInserted: 70");

    deleteNode(20);
    printf("\nDeleted: 20");

    printf("\nDisplayed: ");
    display();

    return 0;
}
