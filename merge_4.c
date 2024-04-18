#include<stdio.h>

void merge(int arr[],int l,int m,int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int i,j,k;
    int arr1[n1];
    int arr2[n2];

    for(i = 0; i<n1;i++)
        arr1[i] = arr[i + l];

    for(j = 0; j<n2;j++)
        arr2[j] = arr[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        if(arr1[i]< arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void split(int arr[],int l,int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2;
        split(arr,l,m);
        split(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void print(int arr[], int n)
{
    int i = 0;
    for(i = 0; i < n; i++){
        printf("%d \t", arr[i]);
    }
    printf("\n\n");
}

void main()
{
    int arr[] = {56,23,87,34,76,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr, n);
    split(arr, 0, n-1);
    print(arr, n);
}
