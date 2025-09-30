#include <iostream>
using namespace std;

bool validCell(int **board, int r, int c, int n){
    if(r >= 0 && c >= 0 && r < n && c < n && board[r][c] == 1){
        return true;
    }
    return false;
}

bool explore(int **board, int r, int c, int n, int **track){
    if(!validCell(board, r, c, n)){
        return false;
    }

    if(r == n-1 && c == n-1){
        track[r][c] = 1;
        return true;
    }

    if(track[r][c] == 1){
        return false;
    }

    track[r][c] = 1;

    if(explore(board, r+1, c, n, track)) return true;
    if(explore(board, r, c+1, n, track)) return true;
    if(explore(board, r-1, c, n, track)) return true;
    if(explore(board, r, c-1, n, track)) return true;

    track[r][c] = 0;
    return false;
}

int main(){
    int n = 5;

    int layout[5][5] = {
        {1,0,1,0,1},
        {1,1,1,1,1},
        {0,1,0,1,1},
        {1,0,0,1,1},
        {1,1,1,0,1}
    };

    int **board = new int*[n];
    int **track = new int*[n];

    for(int r=0; r<n; r++){
        board[r] = new int[n];
        track[r] = new int[n];
        for(int c=0; c<n; c++){
            board[r][c] = layout[r][c];
            track[r][c] = 0;
        }
    }

    if(explore(board, 0, 0, n, track)){
        cout << "Lion got the meat!\n";
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                cout << track[r][c] << " ";
            }
            cout << "\n";
        }
    }
    else{
        cout << "No path available.\n";
    }
}
