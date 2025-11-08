#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

Node* createNode(int data){
	return new Node(data);
}

int countnodes(Node* node){
    if(node == NULL){
        return 0;
    }
    return 1+countnodes(node->left)+countnodes(node->right);
}

int leafnodes(Node* node){
    if(node==NULL) return 0;
    if(node->left==NULL && node->right==NULL){
        return 1;
    }
    return leafnodes(node->right)+leafnodes(node->left);
}

int heightoftree(Node* node){
    if(node==NULL) return 0;

    int heightright=heightoftree(node->right);
    int heightleft=heightoftree(node->left);
    return max(heightright,heightleft)+1;
}

void display(Node *node, int level)
{
    if (node == NULL)   return;
    display(node->right, level + 1);
    for (int i = 0; i < level; i++){
        cout << "\t";
    }
    cout<<" "<<node->data << endl;
    display(node->left, level + 1);
}

int main(){
	
    Node* n1=new Node(5);
	n1->right=createNode(10);
	n1->left=createNode(20);
	n1->right->right = createNode(30);
	n1->right->left = createNode(40);
	n1->left->right = createNode(50);
	n1->left->left = createNode(60);
	n1->left->left = createNode(70);

    cout<<"Number Of Nodes : "<<countnodes(n1)<<endl;
    cout<<"Number Of Leaf Nodes : "<<leafnodes(n1)<<endl;
    cout <<"Height Of Tree : "<<heightoftree(n1);


}
