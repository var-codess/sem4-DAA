#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (1)
    {

        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int partition_r(int arr[], int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low);

    int temp = arr[random];
    arr[random] = arr[low];
    arr[low] = temp;

    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_r(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
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
    int partition(int arr[], int low, int high), partition_r(int arr[], int low, int high);
    void quickSort(int arr[], int low, int high), printArray(int arr[], int n), getData(int x, int arr[]);
    for (int i = 0; i < 1000; i++)
    {

        getData(i + 1, a);
        start = clock();

        quickSort(a, 0, ((i + 1) * 100) - 1);
        end = clock();

        time_req = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%.2lf ", time_req);
    }
    return 0;
}