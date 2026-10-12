#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for the head node: ");
    scanf("%d", &head->data);
    head->next = NULL;
    int n;
    printf("Enter the number of nodes to add: ");
    scanf("%d", &n);
    struct Node *current = head;
    for(int i = 0; i < n; i++){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    current->next = head;
    struct Node *cur=head->next;
    struct Node *prev=head;
    while(cur!=head){
        struct Node *next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    cur->next=prev;
    head=prev;
    struct Node *temp=head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
    return 0;
}