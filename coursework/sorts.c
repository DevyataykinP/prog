#include "sorts.h"

void swap(int *n1, int *n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int j = low;
    for (int i = low; i <= high - 1;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(&arr[i], &arr[j]);
            j++;
        }
    }
    swap(&arr[j], &arr[high]);
    return j;
}

void quick_sort(int *arr, int low, int high)
{
    if(low<high)
    {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

void bubble_sort(int *arr, int size)
{
    int flag = 1;
    while(flag)
    {
        flag = 0;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i; j++)
            {
                if(arr[j]>=arr[j+1])
                {
                    swap(&arr[j], &arr[j+1]);
                    flag = 1;
                }
            }
        }
    }
}
