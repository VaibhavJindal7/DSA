#include <stdio.h>
#include <stdlib.h>

int cnt = 0;
int *subset = NULL;
int *arr;
int n;

void dfs(int target, int val, int idx)
{
    if (val == target)
    {
        printf("Subset : ");
        for (int i = 0; i < cnt; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }

    if (val > target || idx == n)
        return;

    // Take current element
    cnt++;
    subset = realloc(subset, cnt * sizeof(int));
    subset[cnt - 1] = arr[idx];

    dfs(target, val + arr[idx], idx + 1);

    // Backtrack
    cnt--;
    subset = realloc(subset, cnt * sizeof(int));

    // Skip duplicate elements
    while (idx + 1 < n && arr[idx] == arr[idx + 1])
        idx++;

    // Don't take current element
    dfs(target, val, idx + 1);
}

int main()
{
    int target;

    printf("Enter size of array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Enter target: ");
    scanf("%d", &target);

    dfs(target, 0, 0);

    free(arr);
    free(subset);

    return 0;
}
  
  
