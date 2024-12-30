#include <iostream>

void merge(int arr[], int l1, int r1, int l2, int r2)
{
    int temp[r2 - l1 + 1];
    int i = l1, j = l2, k = 0;
    while (i <= r1 && j <= r2)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i];
            i++;
        }
        else
        {
            temp[k++] = arr[j];
            j++;
        }
    }
    while (i <= r1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= r2)
    {
        temp[k++] = arr[j++];
    }
    k = 0;
    for (int i = l1; i < r2 + 1; i++)
    {
        arr[i] = temp[k++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, mid + 1, r);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 5, 4, 12};
    mergeSort(arr, 0, 12);
    for (int i = 0; i < 13; i++)
    {
        std::cout << arr[i] << " ";
    }
}