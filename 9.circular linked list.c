#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insert(int x) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = x;
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
    }
}

void delete(int x) {
    if (head == NULL) return;

    Node *temp = head, *prev = NULL;

    if (head->data == x && head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    if (head->data == x) {
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        free(head);
        head = temp->next;
        return;
    }

    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == x) {
            prev->next = temp->next;
            free(temp);
            return;
        }
    } while (temp != head);
}

void display() {
    if (head == NULL) return;
    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("Circular Linked List: ");
    display();

    delete(20);
    printf("After deleting 20: ");
    display();

    delete(10);
    printf("display 10: ");
    display();

    return 0;
}
