#include <iostream>
using namespace std;

class HashTable
{
public:
    string arr[50];

    HashTable()
    {
        for (int i = 0; i < 50; i++)
            arr[i] = ""; 
    }

    int hash1(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum += (int)s[i];
        }
        return sum % 50;
    }

    int hash2(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum += (int)s[i];
        }
        return 7 - sum % 7;
    }

    void insert(string name)
    {
        int h1 = hash1(name);
        int h2 = hash2(name);

        if (arr[h1] == "")
        {
            arr[h1] = name;
            return;
        }

        for (int i = 1; i < 50; i++)
        {
            int newIndex = (h1 + i * h2) % 50;

            if (arr[newIndex] == "")
            {
                arr[newIndex] = name;
                return;
            }
        }

        cout << "Hash table full" << endl;
    }

    void search(string name)
    {
        int h1 = hash1(name);
        int h2 = hash2(name);

        for (int i = 0; i < 50; i++)
        {
            int curIndex = (h1 + i * h2) % 50;

            if (arr[curIndex] == "")
            {
                break;
            }

            if (arr[curIndex] == name)
            {
                cout << "Employee found at index " << curIndex << endl;
                return;
            }
        }

        cout << "Employee not found " << endl;
    }

    void display()
    {
        for (int i = 0; i < 50; i++)
        {
            cout << i << ": ";
            if (arr[i] == "")
            {}
            else
                cout << arr[i];
            cout << endl;
        }
    }
};

int main()
{
    HashTable h;

    h.insert("hasheem");
    h.insert("Ali");
    h.insert("Mustafa");
    h.insert("Bilaal");

    h.display();

    h.search("Ali");
    h.search("Talha");
}
