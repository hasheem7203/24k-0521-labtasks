#include <iostream>
using namespace std;


class node{
    public:
    string data;
    node* next;
    node(string val){
        data = val;
        next=nullptr;
    }
};

class list {
    node* head;
    node* tail;

    public:
        list(){
            head=tail=NULL;
        }

        void pushfront(string val){
            node* newnode= new node(val);
            if(head==NULL){
                head=tail=newnode;
            }else{
                newnode->next=head;
                head=newnode;
            }
        }
        void display(){
            node *temp=head;
            while (temp!=NULL){
                cout<< temp->data<<",";
                temp=temp->next;
            }
            cout <<endl;
        }

        void pushback(string val){
            node* newnode=new node(val);
            if(head==NULL){
                head=tail=newnode;
            }else{
                tail->next=newnode;
                tail=newnode;
            }
        }
    
        void insertnode(int pos,string val){
            node* newnode=new node(val);
            node* temp=head;
            if(pos == 0){
                newnode->next = head;
                head = newnode;
                if(tail == nullptr) tail = newnode; // if list was empty
                return;
            }
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            if(temp == nullptr){
                cout << "Position out of bounds!" << endl;
                delete newnode;
            return;
            }
        }
        void search(string key){
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
};


int main(){
    list l1;
    l1.pushback("data structures");
    l1.pushback("operating system");
    l1.pushback("computer networks");
    l1.pushback("database system");
    l1.pushfront("artificial intelligence");
    l1.pushback("machine learning");

    l1.insertnode(3, "cyber security");

    l1.search("database system");
    l1.display();

    return 0;
}
