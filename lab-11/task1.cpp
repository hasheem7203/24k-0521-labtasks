#include <iostream>
using namespace std;

class node {
public:
    string data;
    node* next;

    node(string data): data(data), next(NULL) {}
};

class hashtable {
public:
    node* arr[10];

    hashtable() {
        for(int i = 0; i < 10; i++)
            arr[i] = NULL;
    }

    int hashfunction(string s) {
        int sum = 0;
        for(char c : s)
            sum += (int)c;
        return sum % 10;
    }

    void insert(string value) {
        node* newnode = new node(value);
        int index = hashfunction(value);

        if(arr[index] == NULL) {
            arr[index] = newnode;
        } else {
            node* temp = arr[index];
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }

    void display() {
        for(int i = 0; i < 10; i++) {
            cout << "[" << i << "]";
            node* temp = arr[i];

            while(temp != NULL) {
                cout << " -> " << temp->data;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    hashtable arr;

    arr.insert("apple");
    arr.insert("grapes");
    arr.insert("peach");
    arr.insert("banana");
    arr.insert("mango");
    arr.insert("apple");

    arr.display();
}
