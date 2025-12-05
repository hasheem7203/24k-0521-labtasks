#include <iostream>
using namespace std;

int comparisons = 0;

int partitionLast(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    return i + 1;
}

int partitionFirst(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start + 1;

    for (int j = start + 1; j <= end; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[start];
    arr[start] = arr[i - 1];
    arr[i - 1] = temp;

    return i - 1;
}

int partitionRandom(int arr[], int start, int end)
{
    int randomIndex = start + (end - start) / 2;
    int temp = arr[randomIndex];
    arr[randomIndex] = arr[end];
    arr[end] = temp;

    return partitionLast(arr, start, end);
}

int partitionMiddle(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;
    int temp = arr[mid];
    arr[mid] = arr[end];
    arr[end] = temp;

    return partitionLast(arr, start, end);
}

int partitionMedianOfThree(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;

    comparisons += 3;
    if (arr[start] > arr[mid])
    {
        int temp = arr[start];
        arr[start] = arr[mid];
        arr[mid] = temp;
    }
    if (arr[start] > arr[end])
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
    if (arr[mid] > arr[end])
    {
        int temp = arr[mid];
        arr[mid] = arr[end];
        arr[end] = temp;
    }

    int temp = arr[mid];
    arr[mid] = arr[end];
    arr[end] = temp;

    return partitionLast(arr, start, end);
}

void quickSortFirst(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partitionFirst(arr, low, high);
        quickSortFirst(arr, low, pivot - 1);
        quickSortFirst(arr, pivot + 1, high);
    }
}

void quickSortRandom(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partitionRandom(arr, low, high);
        quickSortRandom(arr, low, pivot - 1);
        quickSortRandom(arr, pivot + 1, high);
    }
}

void quickSortMiddle(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partitionMiddle(arr, low, high);
        quickSortMiddle(arr, low, pivot - 1);
        quickSortMiddle(arr, pivot + 1, high);
    }
}

void quickSortMedian(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partitionMedianOfThree(arr, low, high);
        quickSortMedian(arr, low, pivot - 1);
        quickSortMedian(arr, pivot + 1, high);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10] = {10, 7, 8, 9, 1, 5, 55, 12, 59};
    int n = 9;

    int testArr1[10] ={10, 7, 8, 9, 1, 5, 55, 12, 59};
    comparisons = 0;
    quickSortFirst(testArr1, 0, n - 1);
    cout << "First pivot comparisons: " << comparisons << endl;
    print(testArr1, n);

    int testArr3[10] ={10, 7, 8, 9, 1, 5, 55, 12, 59};
    comparisons = 0;
    quickSortRandom(testArr3, 0, n - 1);
    cout << "Random pivot comparisons: " << comparisons << endl;
    print(testArr3, n);

    int testArr4[10] = {10, 7, 8, 9, 1, 5, 55, 12, 59};
    comparisons = 0;
    quickSortMiddle(testArr4, 0, n - 1);

    cout << "Middle pivot comparisons: " << comparisons << endl;
    print(testArr4, n);
    int testArr5[10] = {10, 7, 8, 9, 1, 5, 55, 12, 59};
    comparisons = 0;

    quickSortMedian(testArr5, 0, n - 1);
    cout << "Median pivot comparisons: " << comparisons << endl;
    print(testArr5, n);

    return 0;
}
