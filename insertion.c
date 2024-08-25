#include <stdio.h>
#include <stdlib.h>

typedef struct Node
 {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data)
 {
    Node* r = (Node*) malloc(sizeof(Node));
    if (!r)
 {
        printf("Memory error\n");
        return NULL;
    }
    r->data = data;
    r->next = NULL;
    return r;
}

void insertAtBeginning(Node** head, int data) 
{
    Node* q = createNode(data);
    if (*head == NULL) {
        *head = q;
        return;
    }
 q->next = *head;
    *head = q;
}

void insertAtEnd(Node** head, int data)
 {
    Node* p = createNode(data);
    if (*head == NULL)
     {
        *head = p;
        return;
    }
    Node* lastNode = *head;
    while (lastNode->next) {
        lastNode = lastNode->next;
    }
    lastNode->next = p;
}

void insertAtPosition(Node** head, int data, int position)
 {
    Node* s = createNode(data);
    if (*head == NULL || position == 0)
  {
        s->next = *head;
        *head =s;

        return;
    }
Node* currentNode = *head;
    int currentPosition = 0;
    while (currentNode && currentPosition < position - 1) {
        currentNode = currentNode->next;
        currentPosition++;
    }
    if (currentNode) {
       s->next = currentNode->next;
        currentNode->next = s;
    }
}

void printList(Node* head)
 {
    Node* temp = head;
    while (temp)
     {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
 insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 60);
    printf("After inserting at beginning: ");
    printList(head);

   
    insertAtEnd(&head, 100);
     printf("After inserting at end: ");
    printList(head);

    insertAtPosition(&head, 45,2);
    printf("After inserting at position: ");
    printList(head);

return 0;
}
