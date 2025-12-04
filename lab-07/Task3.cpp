#include <iostream>
using namespace std;

struct Product {
    string name;
    double price;
    string description;
    bool availability;
};


int partition (Product arr[],int low ,int high){
    int pivot = arr[high].price;
    int index=low-1;
    
    for(int i=low;i<high;i++){
        if(arr[i].price<=pivot){
            index++;
            swap(arr[index],arr[i]);
        }
    }
    swap(arr[index+1],arr[high]);
    return index+1;
}

void quicksort(Product arr[],int low ,int high){
    if(low<high){
        int pi =partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

void printProducts(Product arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].name << "\n";
        cout << "Price: $" << arr[i].price << "\n";
        cout << "Description: " << arr[i].description << "\n";
        cout << "Available: " << (arr[i].availability ? "Yes" : "No") << "\n";
        cout << "----------------------\n";
    }
}
int main() {
    Product products[3] = {
        {"Laptop", 1200.50, "Gaming laptop with RTX GPU", true},
        {"Smartphone", 799.99, "Latest model with OLED display", false},
        {"Headphones", 199.99, "Noise-cancelling over-ear headphones", true}
    };

    quicksort(products, 0, 2);

    cout << "Products sorted by price (ascending):\n";
    printProducts(products, 3);

    return 0;
}
