#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    int height;
    Node *left;
    Node *right;

    Node() : data(0), height(0), left(nullptr), right(nullptr) {}
    Node(int data) : data(data), height(0), left(nullptr), right(nullptr) {}
};

class AVLTree
{
public:
    Node *root;

    AVLTree() : root(nullptr) {}
    AVLTree(Node *root) : root(root) {}

    int height(Node *node)
    {
        return node ? node->height : -1;
    }

    int getBalance(Node *node)
    {
        return height(node->left) - height(node->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    Node *deleteNode(Node *root, int key)
    {
        if (root == nullptr)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);

        else if (key > root->data)
            root->right = deleteNode(root->right, key);

        else
        {
            if ((root->left == nullptr) ||
                (root->right == nullptr))
            {
                Node *temp = root->left ? root->left : root->right;

                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                free(temp);
            }
            else
            {
                Node *temp = minValueNode(root->right);

                root->data = temp->data;

                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left),
                               height(root->right));

        int balance = getBalance(root);

        if (balance > 1 &&
            getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 &&
            getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 &&
            getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 &&
            getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
            return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data)
        {
            return rightRotate(node);
        }

        if (balance < -1 && key > node->right->data)
        {
            return leftRotate(node);
        }

        if (balance > 1 && key > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inOrder(Node *node)
    {

        if (node == nullptr)
        {
            return;
        }

        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
};

int main()
{
    AVLTree t1;
    t1.root = t1.insert(t1.root, 100);
    t1.root = t1.insert(t1.root, 80);
    t1.root = t1.insert(t1.root, 120);
    t1.root = t1.insert(t1.root, 70);
    t1.root = t1.insert(t1.root, 90);
    t1.root = t1.insert(t1.root, 110);
    t1.root = t1.insert(t1.root, 130);

    t1.inOrder(t1.root);

    cout << "\n\n";

    t1.deleteNode(t1.root, 80);
    t1.inOrder(t1.root);
}
