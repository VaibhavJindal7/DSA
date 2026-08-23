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
        if(arr[i]>=0&&arr[i]<n){
            int temp =arr[arr[i]];
            arr[arr[i]]=arr[i];
            arr[i]=temp;
   }
   }
   for(int i=1;i<n;i++){
        if(arr[i]!=i){
            printf("Smallest positive missing no: %d",i);
            return 0;
        }
   }
}
