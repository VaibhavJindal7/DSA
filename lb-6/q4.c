#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for the head node: ");
    scanf("%d", &head->data);
    head->next = NULL;
    head->prev = NULL;
    int n;
    printf("Enter the number of nodes to add: ");
    scanf("%d", &n);
    struct Node *current = head;
    for(int i = 0; i < n; i++){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }
    
    struct Node *cur=head;
    struct Node *prev=NULL;
    while(cur!=NULL){
        struct Node *next=cur->next;
        cur->next=prev;
        cur->prev=next;
        prev=cur;
        cur=next;
    }
    head=prev;

    struct Node *temp=head;
    printf("Reversed doubly linked list: ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
    return 0;
}