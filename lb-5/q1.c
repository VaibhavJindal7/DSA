#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    head->next = temp;
    int i=2;
    while (i<=n) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &temp->data);
        if (i<n) {
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            temp->next = newNode;
            temp = newNode;
        } else {
            temp->next = head;
        }
        i++;
    }

    printf("The circular linked list is: ");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("\nEnter the value to be inserted at first position: ");
    int value;  
    scanf("%d", &value);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;

    temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
     head = newNode;

    printf("The circular linked list is: ");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    struct Node *newNode1 = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value to be inserted at last position: ");  
    scanf("%d", &value);
    newNode1->data = value;
    newNode1->next = head;

    temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode1;
    printf("The circular linked list is: ");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\nEnter the value to be inserted at a specific position: ");
    scanf("%d", &value);
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    struct Node *newNode2 = (struct Node*)malloc(sizeof(struct Node));
    newNode2->data = value;
    temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }
    newNode2->next = temp->next;
    temp->next = newNode2;
    temp = head;
    printf("The circular linked list is: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\nList after deleting the first node: ");
    struct Node *firstNode = head;
    head = head->next;
    temp = head;
    while (temp->next != firstNode) {
        temp = temp->next;
    }
    temp->next = head;
    free(firstNode);
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\nEnter the position of the node to be deleted: ");
    scanf("%d", &pos);
    temp = head;
     count = 1;
    while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }
    
    temp->next = temp->next->next;

    printf("The circular linked list is: ");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\nEnter the value to be deleted: ");
    scanf("%d", &value);
    temp = head;
    struct Node *prev = NULL;
    while (temp->data != value && temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = temp->next;
    printf("The circular linked list is: ");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\nList after deleting the last node: ");
    struct Node *prevlastNode = head;
    while (prevlastNode->next->next != head) {
        prevlastNode = prevlastNode->next;
    }
    prevlastNode->next = head;

    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

}