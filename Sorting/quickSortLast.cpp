
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned int swaps = 0;
int swap(int *c, int *d)
{
        int temp;
        temp = *c;
        *c = *d;
        *d = temp;
}

int partition(int a[], int s, int l);

int quickSort(int a[], int s, int l)
{
        if(l>s)
        {
                int j = partition(a,s,l);
                quickSort(a, s, j-1);
                quickSort(a, j+1, l);
        }
        return 0;
}
int partition(int a[], int s, int l)
{
        int i,j,pivot;
        pivot = a[l];
        i = s;
        for(j=s;j<=l-1;j++)
        {
                if(a[j]<pivot)
                {
                        if(a[i]!=a[j])
                        {
                                swap(a+j,a+i);
                                swaps++;
                        }
                        i++;
                }
        }
        if(a[l]!=a[i])
        {
                swap(a+l,a+i);
                swaps++;
        }
        return i;
}

int printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void)
{
        int i,arr_size;
        printf("ENter number of elements\n");
        scanf("%d",&arr_size);
        int a[arr_size];
        printf("Enter arraty elements:\n");
        for(i=0;i<arr_size;i++)
        scanf("%d",&a[i]);
        printf("Given array is \n");
        printArray(a, arr_size);
        quickSort(a,0,arr_size-1);
        printf("Sorted array is \n");
        printArray(a, arr_size);
        printf("Number of swaps=%d\n",swaps);
        return 0;
}
