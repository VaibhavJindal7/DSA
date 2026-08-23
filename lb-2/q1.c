#include <stdio.h>

int main(){

   int arr[100];
   int n;
   
   printf("Enter size of array : ");
   scanf("%d",&n);
    
      for(int i=0;i<n;i++){
        printf("Enter %d element of array : ",i);
        scanf("%d",&arr[i]);
   }

   
   int value;
   int idx;
   
   printf("Enter the value and index at which value is going to insert :");
   scanf("%d %d",&value,&idx);

   for(int i=n;i>=idx;i--){
          arr[i] = arr[i-1];
   }
   arr[idx]=value;
   n=n+1;
   for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
   }
   printf("\n");

   printf("Enter the value which you want to delete : ");
   scanf("%d",&value);
   int k;
   for(int i=0;i<n;i++){
        if(arr[i]==value){
            k=i;
            break;
        }
   }
   for(int i=k;i<n-1;i++){
        arr[i]=arr[i+1];
   }
   n--;
   for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
   }
   printf("\n");
   return 0;
  }
