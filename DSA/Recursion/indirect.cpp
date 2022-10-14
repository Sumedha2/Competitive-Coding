#include <iostream>
using namespace std;

// indirect recursion
// has more than one recursive function
// these functions call each other cyclically

// declaring both functions ahead so there is no error
void funb(int n);
void funa(int n);

void funa(int n){
    if (n>0){
        cout<<n<<"  ";
        // calls funb
        funb(n-1);
    }
}

void funb(int n){
    if (n>1){
        cout<<n<<"   ";
        // calls funa
        funa(n/2);
    }
}

int main(){
    int n=25;
    funa(25);
    // output is 25 24 12 11 5 4 2
}