#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sizes[] = { 4000, 10000};
    int n = 2;

    int a[10000];
    int b[10000];

    printf("Size of array\tBubble Sort(s)\tInsertion Sort(s)\n");

    for (int k = 0; k < n; k++) {
        int n = sizes[k];

        for (int i = 0; i < n; i++) {
            int val = rand() % 10000;
            a[i] = val;
            b[i] = val;
        }

        clock_t s1 = clock();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        clock_t e1 = clock();
        double timeofbubblesort = (double)(e1 - s1) / CLOCKS_PER_SEC;

        clock_t s2 = clock();
        for (int i = 1; i < n; i++) {
            int key = b[i];
            int j = i - 1;
            while (j >= 0 && b[j] > key) {
                b[j + 1] = b[j];
                j--;
            }
            b[j + 1] = key;
        }
        clock_t e2 = clock();
        double timeofinsertionsort = (double)(e2 - s2) / CLOCKS_PER_SEC;

        printf("%d\t%f\t%f\n", n, timeofbubblesort, timeofinsertionsort);
    }

    return 0;
}