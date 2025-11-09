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

bool checkfullbinary(Node* root){
    if(root==NULL) return true;

    if(root->left==NULL &&root->right==NULL) return true;

    if(root->left!=NULL &&root->right!=NULL){
        return checkfullbinary(root->left)&& checkfullbinary(root->right);
    }
    return false;
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
	n1->left->left->left = createNode(70);

if(checkfullbinary(n1)){
    cout <<"Is a full binary tree \n";
}else {
    cout <<"Not a full binary tree \n";
}

display(n1,0);


}
