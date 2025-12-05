#include <iostream>
using namespace std;

void radixSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        int output[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];

        cout << "After digit " << exp << ": \n";
        for (int i = 0; i < n; i++)
            cout << arr[i] << "\n";
        cout << endl;
    }
}

int main()
{
    int products[20] = {
        12345, 98765, 54321, 11111, 99999,
        24680, 13579, 77777, 44444, 88888,
        10101, 20202, 30303, 40404, 50505,
        61616, 72727, 83838, 94949, 50505};

    cout << "Original: ";
    for (int i = 0; i < 20; i++)
        cout << products[i] << "\n";
    cout << "\n\n";

    radixSort(products, 20);

    cout << "\nSorted: \n";
    for (int i = 0; i < 20; i++)
        cout << products[i] << "\n";

    return 0;
}
