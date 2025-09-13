#include <iostream>
using namespace std;


class dynamic2dmatrix{
    private:
        int** arr;
        int r,c;

    public:
        dynamic2dmatrix(int row,int col){
            r=row;
            c=col;
            arr=new int*[r];
            for(int i=0;i<r;i++){
                arr[i]=new int[c];
            }
        
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    arr[i][j]=i+j;
                }
            }
        }

        void dispaly(){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                        cout<<arr[i][j]<<" ";
                }
                cout <<endl;
            }    
        }

        void resize(int row,int col){
            int** temp=new int*[row];
            for(int i=0;i<row;i++){
                temp[i]=new int[col];
            }
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    temp[i][j]=0;
                }
            }
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(i<row&&j<col)
                        temp[i][j]=arr[i][j];
                }
            }

            for (int i=0;i<r;i++){
                delete[] arr[i];
            }
            delete[] arr;
            arr=temp;
            r=row;
            c=col;
        }

        void transpose(){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    arr[i][j]=arr[j][i];
                }
            }
        }
};

int main(){
    dynamic2dmatrix m1(3,3);
    m1.dispaly();
    m1.resize(4,4);
    m1.dispaly();
    m1.resize(2,2);
    
    m1.dispaly();
    m1.transpose();
    m1.dispaly();
}

