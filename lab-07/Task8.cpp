#include <iostream>
#include <string>
using namespace std;

class Order
{
public:
    int orderID;
    string customerName;
    double totalPrice;
};

int partition(Order orders[], int low, int high)
{
    double pivot = orders[high].totalPrice;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (orders[j].totalPrice <= pivot)
        {
            i++;
            Order temp = orders[i];
            orders[i] = orders[j];
            orders[i] = temp;
        }
    }
    Order temp = orders[i + 1];
    orders[i + 1] = orders[high];
    orders[high] = temp;
    return i + 1;
}

void quickSort(Order orders[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(orders, low, high);
        quickSort(orders, low, pi - 1);
        quickSort(orders, pi + 1, high);
    }
}

void printOrders(Order orders[], int size)
{
    cout << "\nSorted Orders by Price:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "ID: " << orders[i].orderID
             << ", Name: " << orders[i].customerName
             << ", Price: $" << orders[i].totalPrice << endl;
    }
}

int main()
{
    Order orders[5] = {
        {101, "A", 299.99},
        {102, "B", 150.50},
        {103, "C", 499.99},
        {104, "D", 75.25},
        {105, "E", 899.00}};

    cout << "Original Orders:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Order ID" << "  " << "Customer-Name  " << " " << "Price" << endl;
        cout << orders[i].orderID << "\t\t " << orders[i].customerName
             << "\t  " << orders[i].totalPrice << endl;
    }

    quickSort(orders, 0, 4);

    cout << "\nSorted Orders:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Order ID" << "  " << "Customer-Name  " << " " << "Price" << endl;
        cout << orders[i].orderID << "\t\t " << orders[i].customerName
             << "\t  " << orders[i].totalPrice << endl;
    }

    return 0;
}
