#include<iostream>
using namespace std;
const int SIZE=10;
class hashnode{
    public :
        int rollno;
        string name;
        hashnode *next;
        hashnode(int rollno,string name){
            this->rollno=rollno;
            this->name=name;
            next=NULL;
        }
};


class hashtable{
    hashnode* arr[SIZE];
    public:
    hashtable(){
        for(int i=0;i<SIZE;i++){
            arr[i]=NULL;
        }
    }
    int hashfunction(int key){
        return key % SIZE;
    }  
    void insert(int key ,string name){
        int index=hashfunction(key);
        hashnode* newnode=new hashnode(key,name);
        if(arr[index]==NULL){
            arr[index]=newnode;
        }else{
            hashnode* temp=arr[index];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    void deletenode(int key){
        int index =hashfunction(key);
        hashnode*temp =arr[index];
        if(temp->rollno==key){
            arr[index]=temp->next;
            delete temp;
            return;
        }else{
            while(temp->next!=NULL && temp->next->rollno!=key){
                temp=temp->next;
            }
            if(temp->next==NULL){
                cout<<"Key not found"<<endl;
                return;
            }else{
                hashnode* todelete=temp->next;
                temp->next=todelete->next;
                delete todelete;
            }   
        }
    }
    void display(){
        for(int i=0;i<SIZE;i++){
            hashnode* temp=arr[i];
            if(temp==NULL){
                cout<<"Bucket "<<i<<": Empty"<<endl;
            }else{
                cout<<"Bucket "<<i<<": ";
                while(temp!=NULL){
                    cout<<"["<<temp->rollno<<","<<temp->name<<"] -> ";
                    temp=temp->next;
                }
                cout<<"NULL"<<endl;
            }
        }
    }
    void search(int key){
    int index = hashfunction(key);
    hashnode* temp = arr[index];

    while(temp != NULL){
        if(temp->rollno == key){
            cout << "Key " << key << " found: " << temp->name << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Key " << key << " not found" << endl;
}

};
int main(){
    hashtable ht;
    ht.insert(1,"Ali");
    ht.insert(2,"Bilal");
    ht.insert(12,"chamber");
    ht.insert(22,"omen");
    ht.display();
    cout<<"After deleting key 12:"<<endl;
    ht.deletenode(12);
    ht.display();
    ht.search(22);
    ht.search(12);
    return 0;
}
