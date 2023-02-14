#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;

    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],
               int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void getData(int x, int arr[])
{
    for (int i = 0; i < x * 100; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

int main()
{

    clock_t start, end;
    double time_req;
    int a[100000];
    for (int i = 0; i < 1000; i++)
    {

        getData(i + 1, a);
        start = clock();

        mergeSort(a, 0, ((i + 1) * 100) - 1);
        end = clock();

        time_req = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%.2lf ", time_req);
    }

    return 0;
}