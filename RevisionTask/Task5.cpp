#include <iostream>
using namespace std;
const int s =5;
bool found =false;

void checkintersection(int rabbit[s][s],int cat[s][s]){

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if(rabbit[i][j]==1 && cat[i][j]==1){
                cout <<"Meeting point at: ("<<i<<","<<j<<")"<<endl;
            }
        }
    }
}

void printSolution(int sol[s][s]){
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------\n";
}

bool issafe(int x,int y,int grid[s][s],int sol[s][s]){
    return (x>=0&&y>=0&&x<s&&y<s&&grid[x][y]==1&&sol[x][y]==0);
}

void solvemaze(int x,int y,int dx,int dy,int grid[s][s],int sol[s][s]){
    if(x==dx&&y==dy&&grid[x][y]==1){
            sol[x][y]=1;
            cout <<"solution found"<<endl;
            found=true;
            printSolution(sol);
            //sol[x][y]=0;              
            return;
    }

    if(issafe(x,y,grid,sol)){
        sol[x][y]=1;
        solvemaze(x,y+1,dx,dy,grid,sol);

        solvemaze(x+1,y,dx,dy,grid,sol);

        solvemaze(x,y-1,dx,dy,grid,sol);
        
        solvemaze(x-1,y,dx,dy,grid,sol);

        sol[x][y]=0;
    }
}




int main(){
    int grid[s][s]={{1,1,1,0,1},
                    {0,1,0,1,1},
                    {1,1,1,1,0},
                    {0,1,0,1,1},
                    {1,1,1,0,1}};

    int rabbit[s][s]={0};
    int cat[s][s]={0};
cout <<"For rabbit: "<<endl;
solvemaze(0,0,2,2,grid,rabbit);
    if(!found){
        cout<<"solution doesn't exist"<<endl;
    }
found=false;
cout <<"For cat: "<<endl;

    solvemaze(4,4,2,2,grid,cat);
    if(!found){
        cout<<"solution doesn't exist"<<endl;
    }
checkintersection(rabbit,cat);
}
