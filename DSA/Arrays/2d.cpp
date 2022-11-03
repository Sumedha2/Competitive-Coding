#include <iostream>
using namespace std;

// 2d arrays
int main(){
    // fully in stack
    int a[3][4]={{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cout<<a[i][j]<<" ";
        }
    }
    cout<<endl;
    // partially in heap
    int *b[3];
    b[0]=new int[4];
    b[1]=new int[4];
    b[2]=new int[4];
    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cout<<b[i][j]<<" ";
        }
    }
    cout<<endl;
    // fully in heap
    int **c;
    c=new int*[3];
    c[0]=new int[4];
    c[1]=new int[4];
    c[2]=new int[4];
    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cout<<c[i][j]<<" ";
        }
    }
}