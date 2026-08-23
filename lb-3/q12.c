#include <stdio.h>

int main(){
   int n;
   printf("Enter size of array : ");
   scanf("%d", &n);

    int arr[n];
   for(int i=0; i<n; i++){
      printf("Enter element %d : ", i+1);
      scanf("%d", &arr[i]);
   }

   for(int i=0;i<n;i++){
        arr[arr[i]-1] =arr[i];
   }

   for(int i=0;i<n;i++){
      if(arr[i]!=i+1){
            printf("Duplicate no is : %d",arr[i]);
            return 0;
        }
   }
   printf("No duplicate no found");
   return 0;
}