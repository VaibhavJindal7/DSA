#include<stdio.h>

int main(){
    int n, m;
    printf("Enter row and col :");
    scanf("%d", &n);
    scanf("%d", &m);
    int arr[n][m];

    printf("Enter element :"); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]); 
        }
    }

    int k = n * m; 
    int row[k];
    int col[k];
    int val[k]; 

    int t = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != 0){
                row[t] = i;
                col[t] = j;
                val[t] = arr[i][j];
                t++;
            }
        }
    }

    printf("\nRow Col Value\n");
    for(int i = 0; i < t; i++){
        printf("%d %d %d \n", row[i], col[i], val[i]);
    }

    return 0;
}
