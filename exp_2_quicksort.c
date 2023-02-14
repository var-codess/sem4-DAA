#include <stdio.h>
#include <time.h>

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {

        if (a[j] < pivot)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[end];
    a[end] = t;
    return (i + 1);
}

void quick(int a[], int start, int end)
{
    if (start < end)
    {
        int p = partition(a, start, end);
        quick(a, start, p - 1);
        quick(a, p + 1, end);
    }
}

void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
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

        quick(a, 0, ((i + 1) * 100) - 1);
        end = clock();

        time_req = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%.2lf ", time_req);
    }

    return 0;
}