#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

void insert(struct Node** head, int x) {
    struct Node* n = createNode(x);
    if (*head == NULL) {
        *head = n;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = n;
}

void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) temp = temp->next;
    temp->next = head2;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    insert(&list1, 1);
    insert(&list1, 2);
    insert(&list1, 3);

    insert(&list2, 4);
    insert(&list2, 5);
    insert(&list2, 6);

    printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    concatenate(&list1, list2);

    printf("Concatenated List: ");
    display(list1);

    return 0;
}
