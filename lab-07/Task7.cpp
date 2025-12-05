#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int exp)
{
    int n = 50;
    int output[50];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, exp);
    }
}

void displayRanks(int arr[], int n)
{
    cout << "Rank\tScore" << endl;
    cout << "----\t-----" << endl;

    for (int i = 0; i < n; i++)
    {
        int rank = i + 1;
        if (i > 0 && arr[i] == arr[i - 1])
        {
            // Find the first occurrence of this score
            int j = i - 1;
            while (j >= 0 && arr[j] == arr[i])
            {
                j--;
            }
            rank = j + 2; // +2 because j is 0-based and we need 1-based rank
        }
        cout << rank << "\t" << arr[i] << endl;
    }
}

int main()
{
    int scores[50] = {
        85, 92, 78, 65, 95, 88, 72, 60, 98, 82,
        75, 90, 68, 55, 96, 89, 77, 63, 99, 84,
        79, 93, 70, 58, 91, 86, 74, 62, 97, 81,
        76, 94, 69, 57, 100, 87, 73, 61, 95, 83,
        80, 92, 67, 59, 90, 85, 71, 64, 88, 82};

    cout << "Original Scores:" << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << scores[i] << " ";
        if ((i + 1) % 10 == 0)
            cout << endl;
    }

    radixSort(scores, 50);

    cout << "\nSorted Scores (Ascending Order):" << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << scores[i] << " ";
        if ((i + 1) % 10 == 0)
            cout << endl;
    }

    displayRanks(scores, 50);

    return 0;
}
