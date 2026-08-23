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

   int max=0;
   int minvalue=arr[0];
   for(int i=1; i<n; i++){
      if(minvalue>arr[i]){
         minvalue=arr[i];
      }
      else if(arr[i]-minvalue>max){
         max=arr[i]-minvalue;
      }
   }
   printf("Maximum profit is : %d", max);
}