#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    int score;
    Node *next;

    Node() : name(""), score(-1), next(nullptr) {}
    Node(string n, int s) : name(n), score(s), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}
    LinkedList(Node *head) : head(head) {}

    void insertAtEnd(string name, int score)
    {
        Node *nn = new Node(name, score);
        if (head == nullptr)
        {
            head = nn;
            return;
        }
        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = nn;

        return;
    }

    int getMaxScore()
    {
        if (!head)
            return 0;
        int maxScore = head->score;
        Node *temp = head->next;
        while (temp != nullptr)
        {
            if (temp->score > maxScore)
                maxScore = temp->score;
            temp = temp->next;
        }
        return maxScore;
    }

    void radixSort()
    {
        if (!head || !head->next)
            return;

        int maxScore = getMaxScore();

        for (int exp = 1; maxScore / exp > 0; exp *= 10)
        {
            Node *temp[10] = {nullptr};
            Node *temp2[10] = {nullptr};

            Node *current = head;
            while (current != nullptr)
            {
                int digit = (current->score / exp) % 10;
                Node *nextNode = current->next;
                current->next = nullptr;

                if (!temp[digit])
                {
                    temp[digit] = current;
                    temp2[digit] = current;
                }
                else
                {
                    temp2[digit]->next = current;
                    temp2[digit] = current;
                }
                current = nextNode;
            }

            head = nullptr;
            Node *last = nullptr;
            for (int i = 0; i < 10; i++)
            {
                if (temp[i])
                {
                    if (!head)
                    {
                        head = temp[i];
                    }
                    else
                    {
                        last->next = temp[i];
                    }
                    last = temp2[i];
                }
            }
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->name << " : " << temp->score << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Node *n1 = new Node("a", 12);
    LinkedList l1(n1);
    l1.insertAtEnd("b", 5);
    l1.insertAtEnd("c", 15);
    l1.insertAtEnd("d", 0);
    l1.insertAtEnd("e", 2);
    l1.insertAtEnd("f", 33);
    l1.insertAtEnd("g", 9);

    l1.radixSort();

    l1.print();

    return 0;
}
