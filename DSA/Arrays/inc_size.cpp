#include <iostream>
using namespace std;

int main(){
    int *p, *q;
    p= new int[5];
    q= new int[10];
    p[0]=1; p[1]=2; p[2]=3; p[3]=4; p[4]=5;
    // create larger array and transfer all elements to that
    for (int i=0; i<5; i++){
        q[i]=p[i];
    }
    delete p;
    // wherever q is pointing, p will point there
    p=q;
    q=NULL;
}