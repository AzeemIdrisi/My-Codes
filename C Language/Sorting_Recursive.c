// PRACTICAL 2 - Sorting Algorithms - Recursive.
// Mohd Azeem | CSE 2B | 2100300100112

#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int b[100], i = low, j = mid + 1, k = low, l;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for (l = 0; l <= high; l++)
    {
        a[l] = b[l];
    }
}
void mergeSort(int array[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void display(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void main()
{
    int i;
    int a[10] = {34, 2, 687, 1, 32, 12, 22, 9, 45, 67};
    mergeSort(a, 0, 9);
    display(a, 10);

    int b[10] = {32, 12, 22, 9, 45, 67, 34, 2, 687, 1};
    quickSort(b, 0, 9);
    display(b, 10);
}

/*
Output:
1 2 9 12 22 32 34 45 67 687
1 2 9 12 22 32 34 45 67 687
*/
