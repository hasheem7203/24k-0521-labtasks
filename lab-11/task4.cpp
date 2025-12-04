#include <iostream>
#include <string>
using namespace std;

class StudentNode {
public:
    int rollNo;
    string name;
    bool occupied;

    StudentNode() {
        rollNo = 0;
        name = "";
        occupied = false;
    }

    StudentNode(int r, string n) {
        rollNo = r;
        name = n;
        occupied = true;
    }
};

class StudentHashTable {
private:
    StudentNode table[15];
    const int SIZE = 15;

    int hashFunction(int rollNo) {
        return rollNo % SIZE;
    }

public:
    void InsertRecord(int rollNo, string name) {
        int idx = hashFunction(rollNo);
        int attempt = 0;

        while (attempt < SIZE) {
            int newIndex = (idx + attempt * attempt) % SIZE;
            if (!table[newIndex].occupied) {
                table[newIndex] = StudentNode(rollNo, name);
                cout << "Inserted " << name << " at index " << newIndex << endl;
                return;
            }
            attempt++;
        }

        cout << "Hash table full, cannot insert " << name << endl;
    }

    void SearchRecord(int rollNo) {
        int idx = hashFunction(rollNo);
        int attempt = 0;

        while (attempt < SIZE) {
            int newIndex = (idx + attempt * attempt) % SIZE;
            if (table[newIndex].occupied && table[newIndex].rollNo == rollNo) {
                cout << "Student found: " << table[newIndex].name << endl;
                return;
            }
            attempt++;
        }

        cout << "Record not found\n";
    }

    void DisplayTable() {
        cout << "Index : RollNo -> Name\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i].occupied)
                cout << i << " : " << table[i].rollNo << " -> " << table[i].name << "\n";
            else
                cout << i << " : ---\n";
        }
    }
};

int main() {
    StudentHashTable sht;

    sht.InsertRecord(101, "Ali");
    sht.InsertRecord(116, "Sara");
    sht.InsertRecord(131, "Hasan");
    sht.InsertRecord(146, "Zara");

    cout << "\nSearch Records:\n";
    sht.SearchRecord(116);
    sht.SearchRecord(200); // not present

    cout << "\nFull Table:\n";
    sht.DisplayTable();

    return 0;
}
