#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// 1. Create Circular Single Linked List
void create(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

// 2. Traverse the Circular Linked List
void traverse() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// 3. Insert at the Beginning
void insert_beg(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
    }
}

// 4. Insert at the End
void insert_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

// 5. Delete from the Beginning
void delete_beg() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        struct Node* to_delete = head;
        temp->next = head->next;
        head = head->next;
        free(to_delete);
    }
}

// 6. Delete from the End
void delete_end() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        struct Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
}

// Menu-driven program
int main() {
    int choice, data;

    while (1) {
        printf("\n--- Circular Single Linked List Operations ---\t");
        printf("1. Create\t");
        printf("2. Traverse\t");
        printf("3. Insert at Beginning\t");
        printf("4. Insert at End\t");
        printf("5. Delete from Beginning\t");
        printf("6. Delete from End\t");
        printf("7. Exit\t");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to create: ");
                scanf("%d", &data);
                create(data);
                break;
            case 2:
                printf("Circular Linked List: ");
                traverse();
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insert_beg(data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insert_end(data);
                break;
            case 5:
                printf("Deleting from the beginning...\n");
                delete_beg();
                break;
            case 6:
                printf("Deleting from the end...\n");
                delete_end();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

return 0;
}