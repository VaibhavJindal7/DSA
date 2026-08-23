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
    
    int ts=0;
    
    for(int i=0; i<n; i++){
          ts+=arr[i];
     }
     int ls=0;
     int f=0;
     for(int i=0;i<n;i++){
         int rt = ts-ls-arr[i];
         if(ls==rt){
                printf("Equilibrium index is : %d",i);
                f=1;
                break;
         }
         ls+=arr[i];
     }
     if(f==0){
        printf("No equilibrium index found");
     }
}