#include <iostream>
using namespace std;

class employee{
public:
    string name;
    int id;
    double salary;

    employee() : name(""), id(0), salary(0.0) {}
    employee(string name, int id, double salary) : name(name), id(id), salary(salary) {}
};

void merge(employee arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    employee *leftArr=new employee[n1];
    employee *rightArr=new employee[n2];
    for(int i=0;i<n1;i++){
        leftArr[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        rightArr[j]=arr[m+j+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(leftArr[i].salary   >=rightArr[j].salary){
            arr[k]=leftArr[i];
            i++;
        }else{
            arr[k]=rightArr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=leftArr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=rightArr[j];
        j++;
        k++;
    }
delete[] leftArr;
delete[] rightArr;
}
void mergesort(employee arr[],int l,int r){
    if(l>=r){
        return;
    }
    int mid=(r+l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int main(){
    employee employees[12] = {
        {"Alice", 101, 75000},
        {"Bob", 102, 62000},
        {"Charlie", 103, 88000},
        {"David", 104, 54000},
        {"Eva", 105, 97000},
        {"Frank", 106, 61000},
        {"Grace", 107, 79000},
        {"Hannah", 108, 83000},
        {"Ian", 109, 72000},
        {"Jack", 110, 68000},
        {"Kate", 111, 91000},
        {"Leo", 112, 67000}
    };
    mergesort(employees,0,12-1);

    cout<<"Sorted array is \n";
    for(int i=0; i<3; i++) {
        cout << i+1 << ". " << employees[i].name 
             << " | ID: " << employees[i].id
             << " | Salary: $" << employees[i].salary << "\n";
    }
    cout<<endl;
}
