#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->next = head;
    head->prev = head;
    struct Node *temp = head;
    int i=2;
    while (i<=n) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = head;
        newNode->prev = temp;
        temp->next = newNode;
        head->prev = newNode;
        temp = newNode;
        i++;
    }

    printf("The circular doubly linked list is: ");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    struct Node *newNode1 = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value to be inserted at first position: ");
    int value;
    scanf("%d", &value);
    newNode1->data = value;
    newNode1->next = head;
    newNode1->prev = temp;
    head = newNode1;
    temp->next = newNode1;
    head->prev = newNode1;
    printf("The circular doubly linked list after insertion at first position is: ");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    struct Node *newNode2 = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value to be inserted at last position: ");
    scanf("%d", &value);
    newNode2->data = value;
    newNode2->next = head;
    newNode2->prev = temp;
    temp->next = newNode2;
    head->prev = newNode2;
    printf("The circular doubly linked list after insertion at last position is: ");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);


}