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
                cout<< temp->data<<"\n";
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
                newnode->next = temp->next;
                temp->next = newnode;
            if(newnode->next == nullptr) tail = newnode; // if inserted at the end
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
        void searchbypos(int pos){
            node* temp=head;
            int index=0;
            while(temp!=NULL){
                if(index==pos){
                    cout<<"Found: "<<temp->data<<endl;
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
    list catalog;
    catalog.pushback("data structures");
    catalog.pushback("operating system");
    catalog.pushback("computer networks");
    catalog.pushback("database system");
    catalog.pushfront("artificial intelligence");
    catalog.pushback("machine learning");

    catalog.insertnode(3, "cyber security");

    cout << "Books in the catalog: \n";
    catalog.display();
    catalog.popfront();
    cout<<"After removing the first book, the catalog is: \n";
    catalog.display();
    cout<<"Searching for 'database system': ";
    catalog.search("database system");
    cout<<"Searching by position 4: ";
    catalog.searchbypos(4);

    return 0;
}
