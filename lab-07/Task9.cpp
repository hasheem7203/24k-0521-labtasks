#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[10];
    int count[10] = {0};
    
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int scores[10] = {10, 56, 10, 8, 5, 6, 9, 3, 0, 4};
    
    cout << "Original: ";
    for (int i = 0; i < 10; i++) cout << scores[i] << " ";
    
    radixSort(scores, 10);
    
    cout << "\nSorted:   ";
    for (int i = 0; i < 10; i++) cout << scores[i] << " ";
    
    return 0;
}
