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
        if(arr[i]<0){
            int temp =arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>0){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=temp;
        }
   }
   for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
   }
}