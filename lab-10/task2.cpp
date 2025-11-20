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

        void maxHeapify(int i) {
            int l = leftChild(i);
            int r = rightChild(i);
            int largest = i;

            if (l < heap_size && heapArr[l] > heapArr[largest])
                largest = l;

            if (r < heap_size && heapArr[r] > heapArr[largest])
                largest = r;

            if (largest != i) {
                swap(heapArr[i], heapArr[largest]);
                maxHeapify(largest);
            }
        }

        int extractMax() {
            if (heap_size <= 0) {
                cout << "Heap is empty" << endl;
                return -1; 
            }
            if (heap_size == 1) {
                heap_size--;
                return heapArr[0];
            }

            int root = heapArr[0];
            heapArr[0] = heapArr[heap_size - 1];
            heap_size--;

            maxHeapify(0);

            return root;
        }



        void insertKey(int key ){           //max heap
            if(heap_size==capacity){
                cout <<"Heap Overflow "<<endl ;
                return;
            }
            heap_size++;
            int i=heap_size-1;
            heapArr[i]=key;
            while(i!=0 && heapArr[parent(i)]<heapArr[i]){
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

    heap patient(10);
    patient.insertKey(1);
    patient.insertKey(2);
    patient.insertKey(3);
    patient.insertKey(5);
    patient.insertKey(4);
    patient.insertKey(6);
    patient.insertKey(7);
    patient.insertKey(8);
    patient.insertKey(9);
    patient.insertKey(10);
    patient.display();
    cout <<endl;
    patient.extractMax();
    patient.display();
    return 0;
}
