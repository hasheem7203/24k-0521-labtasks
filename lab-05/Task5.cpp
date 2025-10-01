#include<iostream>
using namespace std;

int sumDigits(int num){
    if(num==0) return 0;
    return num%10 + sumDigits(num/10);
}

int nested_sum(int num){
    if(num<10 && num>=0) return num;
    return nested_sum(sumDigits(num));
}

int main(){

    int num;
    cout<< "Enter a number: ";
    cin>>num;
    cout<< "The nested sum of digits is: "<< nested_sum(num)<<endl;
}
