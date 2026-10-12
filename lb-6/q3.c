#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){
    int choice;
    struct Node *head = NULL;
    do{
        printf("Press 1 to add a node, 2 to delete a node or 0 to exit: ");
        scanf("%d", &choice);
        if(choice==1){
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter data for the new node: ");
            scanf("%d", &newNode->data);
            newNode->next = head;
            head = newNode;
        }
        else if(choice==2){
            if(head!=NULL){
                struct Node *temp=head;
                head=head->next;
                free(temp);
            }else{
                printf("Linked list is empty\n");
            }
        }
    }while(choice!=0);

    struct Node *temp=head;
    printf("Final linked list: ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
    return 0;
}