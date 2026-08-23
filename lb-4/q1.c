#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main(){
   
   struct Node *head = (struct Node*)malloc(sizeof(struct Node));
   struct Node *second = (struct Node*)malloc(sizeof(struct Node));
   struct Node *third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next =NULL;
    struct Node *t=head;
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data =4;
    newNode->next = head;
    head = newNode;
    struct Node *temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    struct Node *endNode = (struct Node*)malloc(sizeof(struct Node));
    endNode->data = 5;
    endNode->next = NULL;

    struct Node *temp1 = head;

    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = endNode;

    struct Node *temp2 = head;
    while(temp2 != NULL){
        printf("%d ",temp2->data);
        temp2 = temp2->next;
    }
    printf("\n");
    struct Node *temp3 = head;
    struct Node  *temp4 = head;
    while(temp4->next !=NULL){
        temp3 = temp3->next;
        temp4 = temp4->next->next;
    }
    struct Node *middle = (struct Node*)malloc(sizeof(struct Node));
    middle->data = 45;
    struct Node  *x = temp3->next;
    temp3->next = middle;
    middle->next = x;

    struct Node *temp5 = head;
    while(temp5 !=NULL){
        printf("%d ",temp5->data);
        temp5 = temp5->next;
    }
    printf("\n");
    struct Node *idx = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the node value :");
    scanf("%d",&idx->data);
    int n;
    printf("Enter the index in which you want to insert the node: ");
    scanf("%d", &n);
    int cnt =0;
    struct Node *temp6 = head;
    while(cnt != n-1){
        temp6 = temp6->next;
        cnt++;
    }
    idx->next = temp6->next;
    temp6->next = idx;

    struct Node *temp7 = head;
    while(temp7!=NULL){
        printf("%d ",temp7->data);
        temp7 = temp7->next;
    }
    printf("\n");
    printf("Enter the node value you want to delete: ");
    int val;
    scanf("%d",&val);
    struct Node *temp8 = head;
    while(temp8!=NULL && temp8->next !=NULL &&temp8->next->data !=val){
        temp8 = temp8->next;
    }
    struct Node *del = temp8->next;
    temp8->next = del->next;
    free(del);
    struct Node *temp9 = head;
    while(temp9!=NULL){
        printf("%d ",temp9->data);
        temp9 = temp9->next;
    }
    printf("\n");
    printf("Enter the index of the node you want to delete : ");
    int index;
    scanf("%d",&index);
    struct Node *temp10 = head;
    cnt=0;
    while(cnt!=index-1){
        temp10 = temp10->next;
        cnt++;
    }
    struct Node *del1 = temp10->next;
    temp10->next = del1->next;
    free(del1);
    struct Node *temp11 = head;
    while(temp11!=NULL){
        printf("%d ",temp11->data);
        temp11 = temp11->next;
    }
    
}