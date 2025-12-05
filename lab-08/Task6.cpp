#include <iostream>
using namespace std;

class Node
{
public:
    int id;
    Node *left;
    Node *right;

    Node(int id) : id(id), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int id)
{
    if (root == nullptr)
    {
        return new Node(id);
    }

    if (id < root->id)
    {
        root->left = insert(root->left, id);
    }
    else if (id > root->id)
    {
        root->right = insert(root->right, id);
    }
    return root;
}

Node *findCommonAncestor(Node *root, int id1, int id2)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (id1 < root->id && id2 < root->id)
    {
        return findCommonAncestor(root->left, id1, id2);
    }

    if (id1 > root->id && id2 > root->id)
    {
        return findCommonAncestor(root->right, id1, id2);
    }

    return root;
}

void display(Node *root, int level)
{
    if (root == nullptr)
    {
        return;
    }
    display(root->right, level + 1);

    for (int i = 0; i < level; i++)
    {
        cout << "\t\t";
    }

    cout << "ID: " << root->id << endl
         << endl;

    display(root->left, level + 1);
}

int main()
{
    Node *n1 = new Node(152);
    insert(n1, 120);
    insert(n1, 100);
    insert(n1, 180);
    insert(n1, 165);
    insert(n1, 195);
    insert(n1, 151);

    display(n1, 0);

    Node *ancestor = findCommonAncestor(n1, 100, 151);
    cout << "Lowest common ancestor is " << ancestor->id;

    return 0;
}
