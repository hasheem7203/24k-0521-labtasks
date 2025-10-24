#include<iostream>
using namespace std;



void merge(int arr[],int left,int mid, int right ){
    int n1=mid-left+1;
    int n2=right - mid;

    int leftarr[100]={0};
    int rightarr[100]={0};

    for(int i=0; i<n1;i++){
        leftarr[i]=arr[left+i];
    }

    for(int i=0; i<n2;i++){
        rightarr[i]=arr[mid +1+i];
    }
    int i =0,j=0;
    int k =left;

while (i<n1 && j<n2){
    if (leftarr[i]<=rightarr[j]){
        arr[k]=leftarr[i];
        i=i+1;
    }else{
        arr[k]=rightarr[j];
        j++;
    }
    k++;
}
while (i<n1){
    arr[k]=leftarr[i];
    i++;
    k++;
}

while(j<n2){
    arr[k]=rightarr[j];
    j++;
    k++;
}

}




void mergeSort(int arr[],int left ,int right){
    if (left >= right)
        return;

    int mid = (left +right)/ 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(){
    int arr[10]={10,9,8,7,6,5,4,3,2,1};

    mergeSort(arr,0,9);
for(int i=0;i<10;i++){
    cout <<arr[i]<<" ";
}
}
