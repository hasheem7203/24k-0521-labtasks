#include <iostream>
using namespace std;


class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next=nullptr;
        prev=nullptr;
    }
};

class list {
    node* head;
    node* tail;

    public:
        list(){
            head=tail=NULL;
        }

        void pushback(int val){
            node* newnode=new node(val);
            if(head==NULL){
                head=tail=newnode;
            }else{
                tail->next=newnode;
                newnode->prev=tail;
                tail=newnode;
            }
        }
        void display(){
            node *temp=head;
            while (temp!=NULL){
                cout<< temp->data<<"\n";
                temp=temp->next;
            }
            cout <<endl;
        }

 
        void search(int key){
            node* temp=head;
            int index=0;
            while(temp!=NULL){
                if(temp->data==key){
                    cout<<"Found at index: "<<index<<endl;
                    return;
                }
                temp=temp->next;
                index++;
            }
            cout<<"Not Found!"<<endl;
        }

        void popfront(){
            if(head==NULL){
                return ;
            }
            node *temp=head;
            head=temp->next;
            temp->next=nullptr;
            delete temp;
            if(head == nullptr) tail = nullptr; // if list becomes empty
        }
};


int main(){
    list train;
    train.pushback(1);
    train.pushback(2);
    train.pushback(3);
    train.pushback(4);
    train.popfront();
    cout<<"Train after pop front operation: "<<endl;
        train.display();
    cout<<"Searching for compartment 3 in the train: "<<endl;
    train.search(3);



    return 0;
}
