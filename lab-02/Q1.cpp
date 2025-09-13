
#include <iostream>

using namespace std;

class dynamic1dArray {
private:
    int* data;
    int size;
    int capacity;

    

public:
    dynamic1dArray(int Capacity = 1) {
        size =0;
        capacity =Capacity;
        data = new int[capacity];
    }
    
    void resize() {
        capacity *= 2;
        int* temp = new int[capacity];
        for (int i =0;i< size;i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }

    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    void print() const {
        cout<<"Array elements: ";
        for (int i=0;i<size; ++i) {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    ~dynamic1dArray() {
        delete[] data;
    }
};

int main() {
    dynamic1dArray a1;
    for (int i=1;i<=4;++i) {
        a1.push_back(i);
    }
    a1.print();
    return 0;
}
