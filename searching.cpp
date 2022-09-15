#include <bits/stdc++.h>
using namespace std;
bool linearSearch(int arr[], int s, int findNo)
{
    for (int i = 0; i < s; i++)
    {
        if (arr[i] == findNo)
        {
            cout << "found in linear search" << endl;
            return true;
        }
    }
    return false;
}

bool binarySearch_recursive(int arr[], int low, int high, int findNo)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == findNo)
        {
            cout << "found in binary search recursive" << endl;
            return true;
        }
        else if (arr[mid] > findNo)
        {
            binarySearch_recursive(arr, low, mid - 1, findNo);
        }
        else if (arr[mid] < findNo)
        {
            binarySearch_recursive(arr, mid + 1, high, findNo);
        }
    }
    return false;
}

bool binarySearch(int arr[], int size, int findNo)
{
    int low = 0, high = size;
    int mid;
    while (low <= high)
    {
        
        mid = low + (high - low) / 2;
        if (arr[mid] == findNo)
        {
            cout << "found in binary search" << endl;
            return true;
        }
        else if (arr[mid] > findNo)
        {
            high = mid - 1;
        }
        else if(arr[mid] < findNo)
        {
            low = mid + 1;
        }
    }
    return false;
}



int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int s = sizeof(arr) / sizeof(arr[0]);

    bool res = linearSearch(arr, s, 3);
    binarySearch_recursive(arr, 0, s - 1, 3);
    binarySearch(arr, s, 3);
    return 0;
}