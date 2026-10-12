#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[100];
    int top=0;

    stack:
    printf("Press 1 to push an element and -1 to delete an element from the stack or 0 to exit: ");
    int choice;
    scanf("%d", &choice);
    if(choice==-1){
        goto delete;
    }
    if(choice==0){
        goto exit;
    }
    if(top>=100){
        printf("Stack overflow\n");
        goto stack;
    }
    int input;
    printf("Enter the element to push: ");
    scanf("%d", &input);
    arr[top++]=input;
    goto stack;
    
    delete:
    if(top>0){
        top--;
    }else{
        printf("Stack underflow\n");
    }
    goto stack;
    exit:
    printf("Stack elements: ");
    if(top==0){
        printf("Stack is empty\n");
        return 0;
    }
    for(int i=top-1; i>=0; i--){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}