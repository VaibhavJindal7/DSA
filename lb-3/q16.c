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
   int k=0;
   int val[n];
   int fre[n];
   for(int i=0;i<n;i++){
        int cnt=1;
        while(i<n-1 && arr[i]==arr[i+1]){
            cnt++;
            i++;
        }
        val[k]=arr[i];
        fre[k]=cnt;
        k++;
   }
   for(int i=0;i<k;i++){
        printf("Value: %d, Frequency: %d\n", val[i], fre[i]);
   }
}