// C program for Merge Sort 
#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int a, b, c;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (a = 0; a < n1; a++)
        L[a] = arr[l + a];
    for (b = 0; b < n2; b++)
        R[b] = arr[m + 1 + b];

    a = 0; 
    b = 0; 
    c = l; 
    while (a < n1 && b < n2) {
        if (L[a] <= R[b]) {
            arr[c] = L[a];
            a++;
        }
        else {
            arr[c] = R[b];
            b++;
        }
        c++;
    }

    while (a < n1) {
        arr[c] = L[a];
        a++;
        c++;
    }

    while (b < n2) {
        arr[c] = R[b];
        b++;
        c++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int a;
    for (a = 0; a < size; a++)
        printf("%d ", A[a]);
    printf("\n");
}

int main()
{
    int arr[] = { 21, 98, 23, 67, 48, 19 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("GIVEN ARRAY: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSORTED ARRAY: \n");
    printArray(arr, arr_size);
    return 0;
}
