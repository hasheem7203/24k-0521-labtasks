#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int interpolationSearch(int arr[],int n,int key){
    int low=0,high=n-1;

    while(low<=high && key>=arr[low] && key<=arr[high]){
        if(low==high){
            if(arr[low]==key) return low;
            return -1;
        }

        int pos=low+((double)(high-low)/(arr[high]-arr[low]))*(key-arr[low]);

        if(arr[pos]==key){
            return pos;
        }
        if(arr[pos]<key){
            low=pos+1;
        }else{
            high=pos-1;
        }
    }
    return -1;
}

void displayArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Original array: ";
    displayArray(arr,n);

    bubbleSort(arr,n);

    cout<<"Sorted array: ";
    displayArray(arr,n);

    int key;
    cout<<"Enter element to search: ";
    cin>>key;

    int index=interpolationSearch(arr,n,key);
    if(index!=-1){
        cout<<"Element found at index "<<index<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }

    return 0;
}
