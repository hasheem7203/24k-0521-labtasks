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
        node* gethead(){
            return head;
        }
        void addSong(string val){
            node* newnode=new node(val);
            if(head==NULL){
                head=tail=newnode;
                tail->next=head;
            }else{
                tail->next=newnode;
                tail=newnode;
                tail->next=head;
            }
        }



        void display(){
            node *temp=head;
            do
            {
                cout<< temp->data<<"\n";
                temp=temp->next;                
            } while (temp!=head);
            cout <<endl;
        }

        void delete_song(string val){
            if(head==NULL){
                return;
            }
            if(head==tail && head->data==val){
                delete head;
                head=tail=NULL;
                return;
            }

            node* current=head;
            do
            {
                if(current->data==val){
                    if(current==head){
                        head=head->next;
                        tail->next=head;
                        delete current;
                        return;
                    }else if(current==tail){
                         node* temp=head;
                         while(temp->next!=tail){
                            temp=temp->next;
                        }
                        delete tail;
                        tail=temp;
                        tail->next=head;
                        return;
                    }else{
                        node* temp=head;
                        while(temp->next!=current){
                            temp=temp->next;
                        }
                        node* nodetobedeleted=current;
                        temp->next=current->next;
                        delete nodetobedeleted;
                        return;
                    }
                }
                current=current->next;
            } while (current!=head);
        }

        void playplaylist(int n){
            node* temp=head;
            for(int i=0;i<n;i++){
                cout<<"Playing: "<<temp->data<<endl;
                temp=temp->next;
            }
        }


        ~list() {
            if (head == nullptr) return;
            node* current = head;
            tail->next = nullptr;
            while (current != nullptr) {
                node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = tail = nullptr;
        }
};

int main() {
    list playlist;

    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");

    cout << "Playlist:\n";
    playlist.display();

    cout << "\nDeleting Song A :\n";
    playlist.delete_song("Song A");
    playlist.display();

    cout << "Playing playlist :\n";
    playlist.playplaylist(5);

    return 0;
}
