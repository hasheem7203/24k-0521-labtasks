#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guess(int num){
    int num1,num2;
        cout<<"Player 1: \n";
        cout<<"Guess a Number : ";
        cin>>num1;
        if(num1==num){
            cout<<"player1 win";
            return;
        }else if(num1>num){
            cout <<"player 1 guess lower"<<endl;
        }else{
            cout<<"player 1 guess higher"<<endl;
        }
        cout<<"Player 2: \n";
        cout<<"Guess a Number : ";
        cin>>num2;
        if(num2==num){
            cout<<"player2 win";
            return;
        }else if(num2>num){
            cout <<"player 2 guess lower"<<endl;
        }else{
            cout<<"player 2 guess higher"<<endl;
        }
        guess(num);
}


int main() {
    srand(time(0));


    int min_value = 1;
    int max_value = 100;
    int random_number = min_value + (rand() % (max_value - min_value + 1));

    guess(random_number);
    return 0;
}
