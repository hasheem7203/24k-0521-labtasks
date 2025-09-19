#include <iostream>
using namespace std;

void shellSort(int arr[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            int j=i;
            while(j>=gap && arr[j-gap]>temp){
                arr[j]=arr[j-gap];
                j-=gap;
            }
            arr[j]=temp;
        }
    }
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

    shellSort(arr,n);

    cout<<"Sorted array (Shell Sort): ";
    displayArray(arr,n);

    return 0;
}
