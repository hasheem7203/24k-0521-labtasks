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
        node* gethead(){
            return head;
        }
        void sortlist(){
            if(head==NULL || head->next==NULL){
                return;
            }
            bool swapped;
            do{
                swapped=false;
                node* current=head;
                while(current->next!=NULL){
                    if(current->data>current->next->data){
                        swap(current->data,current->next->data);
                        swapped=true;
                    }
                    current=current->next;
                }
            }while(swapped);
        }


        void concat(list &l2){
            if(head==NULL){
                head=l2.head;
                tail=l2.tail;
                return;
            }
            if(l2.head==NULL){
                return;
            }
            tail->next=l2.head;
            l2.head->prev=tail;
            tail=l2.tail;
        }

        node* middlenode(){
            node* slow=head;
            node* fast=head;
            while(fast!=NULL&&fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }

        void remove_duplicates(){
            if(head==NULL)  return;
            node* current=head;
            while(current!=NULL){
                node *temp=current;
                while(temp->next!=NULL){
                    if (current->data==temp->next->data){
                        node* nodetobedeleted=temp->next;
                        if(temp->next==tail){
                            tail=temp;
                            tail->next=nullptr;
                        }else{
                            temp->next=temp->next->next;
                        }
                         delete nodetobedeleted;
                    }else{
                        temp=temp->next;
                    }
                }
                current=current->next;
            }
        }

        node* merge2sortedLists(node* h1,node*h2){
            if (h1==NULL||h2==NULL){
                return h1==NULL ? h2:h1;
            }

            if(h1->data<=h2->data){
                h1->next=merge2sortedLists(h1->next,h2);
                return h1;
            }else{
                h2->next=merge2sortedLists(h1,h2->next);
                return h2;
            }
        }

        void merge2sortedList(list &l2){
            head=merge2sortedLists(head,l2.head);
            // update tail
            node* temp=head;
            while(temp!=NULL && temp->next!=NULL){
                temp=temp->next;
            }
            tail=temp;
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
 
};


int main(){
list l1, l2;

    l1.pushback(5);
    l1.pushback(1);
    l1.pushback(3);
    l1.pushback(5);
    l1.pushback(2);

    cout << "List 1 before sorting & removing duplicates:\n";
    l1.display();

    l1.sortlist();
    cout << "List 1 after sorting:\n";
    l1.display();

    l1.remove_duplicates();
    cout << "List 1 after removing duplicates:\n";
    l1.display();

    l2.pushback(4);
    l2.pushback(6);
    l2.pushback(8);

    cout << "List 2:\n";
    l2.display();

    l1.concat(l2);
    cout << "After concatenation (l1 + l2):\n";
    l1.display();

    node* mid = l1.middlenode();
    if (mid) {
        cout << "Middle element of concatenated list: " << mid->data << "\n";
    }

    list l3, l4;
    l3.pushback(1);
    l3.pushback(3);
    l3.pushback(5);

    l4.pushback(2);
    l4.pushback(4);
    l4.pushback(6);

    cout << "List 3:\n";
    l3.display();
    cout << "List 4:\n";
    l4.display();

     l3.merge2sortedList(l4);
    cout << "After merging l3 and l4 (sorted merge):\n";
    l3.display();

    return 0;
}
