#include <stdio.h>
#include <iostream>

void merge(int arr[], int s, int e)
{
    int mid = (s + e) / 2;

    int l1 = mid - s + 1;
    int l2 = e - mid;

    int *first = new int[l1];
    int *second = new int[l2];

    int mainArrIndx = s;

    for (int i = 0; i < l1; i++)
        first[i] = arr[mainArrIndx++];

    for (int i = 0; i < l2; i++)
        second[i] = arr[mainArrIndx++];

    int ind1 = 0;
    int ind2 = 0;

    mainArrIndx = s;

    while (ind1 < l1 && ind2 < l2)
    {
        if (first[ind1] < second[ind2])
            arr[mainArrIndx++] = first[ind1++];
        else
            arr[mainArrIndx++] = second[ind2++];
    }

    while (ind1 < l1)
        arr[mainArrIndx++] = first[ind1++];
    while (ind2 < l2)
        arr[mainArrIndx++] = second[ind2++];

    delete[] first;
    delete[] second;
}

void msort(int arr[], int s, int e)
{

    if (s >= e)
        return;

    int mid = (s + e) / 2;

    msort(arr, s, mid);

    msort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[] = {2, 4, 1, 6, 5};
    msort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << std::endl;
    return 0;
}
