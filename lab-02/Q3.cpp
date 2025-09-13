#include <iostream>
using namespace std;

int main() {
    int teams;
    cout << "Enter number of teams: ";
    cin >> teams;

    int* teamSizes = new int[teams];
    int** scores = new int*[teams];

    for (int i=0;i <teams; i++) {
        cout<<"Enter number of players in team "<<i+1<<": ";
        cin>>teamSizes[i];
        scores[i] = new int[teamSizes[i]];
    }

    for (int i = 0; i < teams; i++) {
        cout<<"Team "<<i+1<<" \n";
        for(int j=0;j<teamSizes[i];j++) {
            cout<<"Player "<<j+1<<" score : ";
            cin>>scores[i][j];
        }
    }
    for(int i=0;i<teams;i++) {
        int sum = 0;
        for (int j=0;j<teamSizes[i];j++) {
            sum += scores[i][j];
        }
        cout << "Team "<<i+1<<"Score : " << sum << endl;
    }

    for (int i = 0; i < teams; i++) {
        delete[] scores[i];
    }
    delete[] scores;
    delete[] teamSizes;

    return 0;
}
