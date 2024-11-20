#include <stdio.h>
#define MAXSIZE 10
int cq[MAXSIZE];
int rear = -1, front = -1;
void insert();
void delete1();
void display();
void main() {
 int choice;
 do {
 printf("\n-----CIRCULAR QUEUE-----");
 printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit");
 printf("\nEnter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 insert();
 break;
 case 2:
 delete1();
 break;
 case 3:
 display();
 break;
 case 4:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice. Try again.\n");
 }
 } while (choice != 4);
}
void insert() {
 int n;
 if ((front == (rear + 1) % MAXSIZE)) { // Condition for queue full
 printf("Queue is overflow\n");
 } else {
 printf("Enter the element: ");
 scanf("%d", &n);
 if (rear == -1 && front == -1) { // Initial insertion
 rear = front = 0;
 } else {
 rear = (rear + 1) % MAXSIZE; // Increment rear circularly
 }
 cq[rear] = n;
 printf("Inserted: %d\n", n);
 }
}
void delete1() {
 if (rear == -1 && front == -1) { // Condition for queue empty
 printf("Queue is empty\n");
 } else {
 int n = cq[front];
 if (front == rear) { // Single element case
 rear = front = -1;
 } else {
 front = (front + 1) % MAXSIZE; // Increment front circularly
 }
 printf("Deleted: %d\n", n);
 }
}
void display() {
 if (rear == -1 && front == -1) { // Queue empty
 printf("Queue is empty\n");
 } else {
 printf("The elements in the queue are: ");
 int i = front;
 while (1) {
 printf("%d ", cq[i]);
 if (i == rear) // Stop when the end is reached
 break;
 i = (i + 1) % MAXSIZE; // Increment circularly
 }
 printf("\n");
 }
}
