#include <iostream>

using namespace std;

class heap{
    int capacity;
    int heap_size;
    int* heapArr;
    
    public:
        heap(int capacity): capacity(capacity),heap_size(0){
            heapArr=new int[capacity];
        }

        int parent(int i) { return (i - 1) / 2; }

        int leftChild(int i) { return (2 * i) + 1; }
        int rightChild(int i) { return (2 * i) + 2; }


        void insertKey(int key ){           //min heap
            if(heap_size==capacity){
                cout <<"Heap Overflow "<<endl ;
                return;
            }
            heap_size++;
            int i=heap_size-1;
            heapArr[i]=key;
            while(i!=0 && heapArr[parent(i)]>heapArr[i]){
                swap(heapArr[i],heapArr[parent(i)]);
                i=parent(i);
            }
        }
        void display(){
            for(int i =0;i<heap_size;i++){
                cout <<heapArr[i]<< " ";
            }
            return;
        }

};


int main(){

    heap courier(5);
    courier.insertKey(1);
    courier.insertKey(3);
    courier.insertKey(4);
    courier.insertKey(5);

    courier.display();
    cout <<endl;
    //inserting  2
    courier.insertKey(2);

    courier.display();
}
