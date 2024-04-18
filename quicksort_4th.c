#include<stdio.h>

void swap(int *a,int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int quicksort(int arr[],int l,int r)
{
    int p = l;
    int q = r;
    int pivot = arr[l];

    while(p < q)
    {
        while(arr[p] < pivot && p <= r )
        {
            p++;
        }
        while(arr[q] > pivot && q >= l)
        {
            q--;
        }
        swap(&arr[p],&arr[q]);
    }
    swap(&pivot,&arr[q]);
    return q;
}

void divide(int arr[],int l, int r)
{
    if(l < r)
    {
        int k = quicksort(arr,l,r);
        divide(arr,l,k-1);
        divide(arr,k+1,r);
    }
}

void print(int arr[],int n)
{
    int i;
    for(i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void main()
{
    int arr[] = {25,5,15,45,65,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    divide(arr,0,n-1);
    print(arr,n);
}