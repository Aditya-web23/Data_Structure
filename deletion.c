#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}
void delete_at_beginning(struct node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
void delete_at_end(struct node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct node *temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}
void delete_at_position(struct node **head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct node *temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    struct node *prev = NULL;
    for (int i = 0; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void traverse(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct node *head = NULL;
    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    insert_at_end(&head, 50);

    printf("Original List: ");
    traverse(head);
    delete_at_beginning(&head);
    printf("After deleting at the beginning: ");
    traverse(head);

    delete_at_end(&head);
    printf("After deleting at the end: ");
    traverse(head);

    delete_at_position(&head, 1);
    printf("After deleting at position 1: ");
    traverse(head);

    return 0;
}