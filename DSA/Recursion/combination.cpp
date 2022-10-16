#include <iostream>
using namespace std;

// selection nCr using recursion
int com(int n, int r){
    if(r==0||n==r){
        return 1;
    }
    return com(n-1, r-1)+com(n-1, r);
}


int main(){
    cout<<com(5, 3);
}