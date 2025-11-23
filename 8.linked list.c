#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert(struct node* head, int x) {
    struct node* n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    if (head == NULL) {
        printf("Inserted: %d\n", x);
        return n;
    }
    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
    printf("Inserted: %d\n", x);
    return head;
}

struct node* delete(struct node* head, int x) {
    if (head == NULL) return head;

    if (head->data == x) {
        struct node* t = head;
        head = head->next;
        printf("Deleted: %d\n", t->data);
        free(t);
        return head;
    }

    struct node* temp = head;
    while (temp->next != NULL && temp->next->data != x)
        temp = temp->next;

    if (temp->next != NULL) {
        struct node* d = temp->next;
        temp->next = temp->next->next;
        printf("Deleted: %d\n", d->data);
        free(d);
    }

    return head;
}

void display(struct node* head) {
    printf("Displayed: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    display(head);

    head = delete(head, 20);
    display(head);

    return 0;
}
