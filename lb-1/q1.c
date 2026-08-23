#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], nums[n];
    int npos = 0, nneg = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &arr[i]);

        if (arr[i] > 0)
            npos++;
        else
            nneg++;
    }

    if (npos < nneg || npos - nneg > 1)
    {
        printf("Can't possible");
        return 0;
    }

    int pos = 0, neg = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            nums[pos] = arr[i];
            pos += 2;
        }
        else
        {
            nums[neg] = arr[i];
            neg += 2;
        }
    }

    printf("\nRearranged Array:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}