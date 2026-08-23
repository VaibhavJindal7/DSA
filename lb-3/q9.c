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

   int rp[n];
   int rpv=1;
   for(int i=0;i<n;i++){
        rp[i]=rpv;
        rpv=rpv*arr[i];
   }

   int lp=1;
   for(int i=n-1;i>=0;i--){
        rp[i]=rp[i]*lp;
        lp=lp*arr[i];
   }

   for(int i=0;i<n;i++){
        printf("%d ", rp[i]);
   }

}