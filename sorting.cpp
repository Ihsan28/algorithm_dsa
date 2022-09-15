#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int size)
{
    int i=0;
    while(size>i){
        cout<<arr[i]<<"  ";
        i++;
    }
    cout<<endl;
}

void selectionSort(int arr[], int size)
{
    int i,j,min_idx;

    for(i=0;i<size;i++)
    {
        min_idx=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                swap(arr[j],arr[min_idx]);
            }
        }
    }

    print(arr,size);
}

void insertionSort(int arr[], int size){
    int i, key,j;

    for(i=1;i<size;i++)
    {
        key=arr[i];
        j=i-1;

        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;  
    }

    print(arr,size);
}

void merge(int arr[], int left, int mid, int right)
{
    int l_size=mid-left+1;
    int r_size=right-mid;

    int arr_l[l_size],arr_r[r_size];

    for(int i=0;i<l_size;i++)
    {
        arr_l[i]=arr[left+i];
    }
    for(int j=0;j<r_size;j++)
    {
        arr_r[j]=arr[mid+j+1];
    }

    int l_count=0,r_count=0, arr_count=left;

    while(l_count<l_size&&r_count<r_size)
    {
        if(arr_l[l_count]<arr_r[r_count])
        {
            arr[arr_count]=arr_l[l_count];
            l_count++;
        }
        else{
            arr[arr_count]=arr_r[r_count];
            r_count++;
        }
        arr_count++;
    }

    while(l_count<l_size)
    {
        arr[arr_count]=arr_l[l_count];
        arr_count++;
        l_count++;
    }
    while(r_count<r_size)
    {
        arr[arr_count]=arr_r[r_count];
        arr_count++;
        r_count++;
    }
}

void mergSort(int arr[],int left, int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;

        mergSort(arr,left,mid);
        mergSort(arr,mid+1,right);

        merge(arr,left,mid,right);
        print(arr,right);

    }
}

int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1;

    for(int j=0;j<high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(int arr[],int low, int high)
{
    if(low<high)
    {
        int pi= partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main()
{
    int arr[] = {9,8,7,2, 3, 4, 5, 6};
    int s = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr,s);
    int arr1[] = {9,8,7,2, 3, 4, 5, 6};
    insertionSort(arr1,s);
    int arr2[] = {38,27,43,3,9,82,10,20};
    mergSort(arr2,0,s);
    print(arr2,s);
    int arr3[] = {9,8,7,2, 3, 4, 5, 6};
    quickSort(arr3,0,s-1);
    print(arr3,s);

    return 0;
}