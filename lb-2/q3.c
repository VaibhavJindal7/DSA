#include <stdio.h>

int main(){
  
 int n;
   
   printf("Enter size of array : ");
   scanf("%d",&n);
    int arr[n];
   for(int i=0;i<n;i++){
        printf("Enter %d element of array : ",i);
        scanf("%d",&arr[i]);
   }
int k;
   
   printf("Enter the value of K:");
   scanf("%d",&k);

   for(int i=0;i<n/2;i++){
      int temp = arr[i];
      arr[i] =arr[n-i-1];
      arr[n-i-1]=temp;
   }

   for(int i=0;i<k/2;i++){
       int temp = arr[i];
       arr[i]=arr[k-i-1];
       arr[k-i-1]=temp;
  }
  for(int i = k;i<(n+k)/2;i++){
       int temp = arr[i];
       arr[i]=arr[n+k-i-1];
       arr[n+k-i-1]=temp;
  }
   for(int i=0;i<n;i++){
     printf("%d ",arr[i]);
}
return 0;
}