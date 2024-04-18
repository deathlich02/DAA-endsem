#include<stdio.h>

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printarr(int arr[],int n)
{
    int i;
    for(i = 0;i < n;i ++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void heapify(int heap[],int n,int root)
{
    int largest  = root;
    int left  = 2*root + 1;
    int right = 2*root + 2;

    if(left < n && heap[largest] < heap[left])
        largest = left;
    if(right < n && heap[largest] < heap[right])
        largest = right;

    if(largest != root)
    {
        swap(&heap[largest],&heap[root]);
        heapify(heap,n,largest);
    }
}

void heapsort(int heap[],int n)
{
    int i;
    for(i = n/2-1;i >= 0;i--)
        heapify(heap,n,i);
        
    printarr(heap, n);

    for(i = n-1;i >= 0;i--)
    {
        swap(&heap[0],&heap[i]);
        heapify(heap,i,0);
    }
}

void main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr,n);
    printf("Sorted array is\n");
    printarr(arr, n);
}

