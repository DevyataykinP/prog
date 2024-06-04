#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int *arr1, *arr2;
    double timequick,timebubble;
    clock_t start,end;

    for(int size=5000; size <=100000; size += 5000)
    {
        arr1=(int *)malloc(sizeof(int) * size);
        assert((arr1 != NULL) && "Can't allocate memory");
        arr2=(int *)malloc(sizeof(int) * size);
        assert((arr2 != NULL) && "Can't allocate memory");

        for(int i=0;i<size;++i)
        {
            arr1[i]=arr2[i]=rand()%100000;
        }

        start=clock();
        quick_sort(arr1,0,size-1);
        end=clock();
        timequick=(double)(end-start)/CLOCKS_PER_SEC;
        start=clock();
        bubble_sort(arr2,size);
        end=clock();
        timebubble=(double)(end-start)/CLOCKS_PER_SEC;

        for(int i=0; i<size-1;++i)
        {
            assert((arr1[i] <= arr1[i+1]) && "Array 1 is not sorted");
        }
        for(int i=0; i<size-1;++i)
        {
            assert((arr2[i] <= arr2[i+1]) && "Array 2 is not sorted");
        }

        printf("%d\t%f\t%f\n", size, timequick, timebubble);
        free(arr1);
        free(arr2);
    }
    return 0;
}
