#include <iostream>
using namespace std;

class Node
{
public:
    int id;
    int quantity;
    Node *left;
    Node *right;

    Node(int id, int quantity) : id(id), quantity(quantity), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int id, int quantity)
{
    if (root == nullptr)
    {
        return new Node(id, quantity);
    }

    if (id < root->id)
    {
        root->left = insert(root->left, id, quantity);
    }
    else if (id > root->id)
    {
        root->right = insert(root->right, id, quantity);
    }
    else
    {
        root->quantity = quantity;
        cout << "Product " << id << " Quantity updated" << endl;
    }
    return root;
}
Node *search(Node *root, int id)
{
    if (root == nullptr || root->id == id)
    {
        return root;
    }

    if (id < root->id)
    {
        return search(root->left, id);
    }
    else
    {
        return search(root->right, id);
    }
}

void findMaxQuantity(Node *root, int &maxQuantity, int &productId)
{
    if (root == nullptr)
        return;

    if (root->quantity > maxQuantity)
    {
        maxQuantity = root->quantity;
        productId = root->id;
    }

    findMaxQuantity(root->left, maxQuantity, productId);
    findMaxQuantity(root->right, maxQuantity, productId);
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

    cout << "ID: " << root->id << ", Quantity: " << root->quantity << endl
         << endl;

    display(root->left, level + 1);
}

int main()
{
    Node *n1 = new Node(152, 10);
    insert(n1, 120, 99);
    insert(n1, 100, 112);
    insert(n1, 180, 55);
    insert(n1, 165, 0);
    insert(n1, 195, 86);
    insert(n1, 151, 23);

    display(n1, 0);
    cout << endl
         << endl;

    insert(n1, 120, 5);
    display(n1, 0);

    Node *ns = search(n1, 120);
    cout << "Searched node Id: " << ns->id << " and Quantity: " << ns->quantity << endl;

    int maxQuantity = 0;
    int productID=0;
    findMaxQuantity(n1,maxQuantity,productID);
   cout << "Maximum node Id: " << productID << " and Quantity: " << maxQuantity << endl;

    return 0;
}
