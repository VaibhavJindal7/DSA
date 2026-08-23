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
   
   int fl=arr[0];
   int sl;
   if(arr[1]>arr[0]){
       sl=arr[0];
       fl=arr[1];
   }else{
       sl=arr[1];
   }
   for(int i=2;i<n;i++){
       if(arr[i]>fl){
           sl=fl;
           fl=arr[i];
       }else if(arr[i]>sl){
           sl=arr[i];
       }
   }
   printf("First largest: %d, Second largest: %d",fl,sl);
   printf("\n");
  
   int fs=arr[0];
   int ss;
   if(arr[1]<arr[0]){
       ss=arr[0];
       fs=arr[1];
   }else{
       ss=arr[1];
   }
   for(int i=2;i<n;i++){
       if(arr[i]<fs){
           ss=fs;
           fs=arr[i];
       }else if(arr[i]<ss){
           ss=arr[i];
       }
   }
printf("First smallest: %d, Second smallest: %d",fs,ss);
return 0;
}