#include <iostream>
using namespace std;
const int s =4;


bool issafe(int x,int y,int grid[s][s],int sol[s][s]){
    return (x>=0&&y>=0&&x<s&&y<s&&grid[x][y]==1&&sol[x][y]==0);
}

bool solvemaze(int x,int y,int grid[s][s],int sol[s][s]){
    if(x==s-1&&y==s-1&&grid[x][y]==1){
            sol[x][y]=1;
            return true;
    }

    if(issafe(x,y,grid,sol)){
        sol[x][y]=1;
        if(solvemaze(x,y+1,grid,sol)){
            return true;
        }
        if(solvemaze(x+1,y,grid,sol)){
            return true;
        }
        if(solvemaze(x,y-1,grid,sol)){
            return true;
        }
        if(solvemaze(x-1,y,grid,sol)){
            return true;
        }
        sol[x][y]=0;
    }
    return false;       //this line is responsible ,if no safe routes exists the function returns false
}


int main(){
    int grid[s][s] ={{1,1,0,1},
                    {0,1,1,0},
                    {1,1,0,1},
                    {0,1,1,1}};

    int sol[s][s]={0};


    if(solvemaze(0,0,grid,sol)){
        cout<<"solution exist"<<endl;
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<"solution doesn't exist"<<endl;
    }

}
