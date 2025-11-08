#include <iostream>

using namespace std;

class Node{
public:
    string package;
    Node *left;
    Node *right;
    Node(string package) : package(package), left(NULL), right(NULL) {}
};

Node* createNode(string package){
	return new Node(package);
}
void display(Node *node, int level)
{
    if (node == NULL)   return;


    display(node->right, level + 1);

    for (int i = 0; i < level; i++){
        cout << "\t";
    }

    cout<<" "<<node->package << endl;
    display(node->left, level + 1);
}

int main(){
	
    Node* n1=new Node("Tours");
	n1->right=createNode("Pakistan");
	n1->left=createNode("india");
	n1->right->right = createNode("north Pakistan");
	n1->right->left = createNode("south Pakistan");
	n1->left->right = createNode("north india");
	n1->left->left = createNode("south india");
	
    display(n1,0);

}
