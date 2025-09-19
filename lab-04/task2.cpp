#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[],int n,int &comparisons){
    comparisons=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            comparisons++;
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[],int n,int &comparisons){
    comparisons=0;
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0){
            comparisons++;
            if(arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }else{
                break;
            }
        }
        arr[j+1]=key;
    }
}

void selectionSort(int arr[],int n,int &comparisons){
    comparisons=0;
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            comparisons++;
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            swap(arr[i],arr[minIndex]);
        }
    }
}

void shellSort(int arr[],int n,int &comparisons){
    comparisons=0;
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            int j=i;
            while(j>=gap){
                comparisons++;
                if(arr[j-gap]>temp){
                    arr[j]=arr[j-gap];
                    j-=gap;
                }else{
                    break;
                }
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

void runSorts(int arr[],int n,bool showSorted){
    int comparisons;
    int temp[100];

    // Bubble
    for(int i=0;i<n;i++) temp[i]=arr[i];
    bubbleSort(temp,n,comparisons);
    cout<<"Bubble Sort comparisons = "<<comparisons<<endl;
    if(showSorted){ displayArray(temp,n); }

    // Insertion
    for(int i=0;i<n;i++) temp[i]=arr[i];
    insertionSort(temp,n,comparisons);
    cout<<"Insertion Sort comparisons = "<<comparisons<<endl;
    if(showSorted){ displayArray(temp,n); }

    // Selection
    for(int i=0;i<n;i++) temp[i]=arr[i];
    selectionSort(temp,n,comparisons);
    cout<<"Selection Sort comparisons = "<<comparisons<<endl;
    if(showSorted){ displayArray(temp,n); }

    // Shell
    for(int i=0;i<n;i++) temp[i]=arr[i];
    shellSort(temp,n,comparisons);
    cout<<"Shell Sort comparisons = "<<comparisons<<endl;
    if(showSorted){ displayArray(temp,n); }
}

int main(){
    srand(time(0));

    int arr[100];
    int n=20;

    for(int i=0;i<n;i++){
        arr[i]=rand()%100+1;
    }

    cout<<"Original array (20 elements): ";
    displayArray(arr,n);
    runSorts(arr,n,true);

    cout<<"\n--- Now with 100 random integers ---\n";
    n=100;
    for(int i=0;i<n;i++){
        arr[i]=rand()%100+1;
    }

    cout<<"Original array (100 elements): ";
    displayArray(arr,n);
    runSorts(arr,n,false);

    return 0;
}
