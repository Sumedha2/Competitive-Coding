#include <iostream>
using namespace std;

// taylor series using horner's rule

double tayl(int x, int n){
    static double s;
    if (n==0){
        return s;
    }
    s=1+x*s/n;
    return tayl(x, n-1);
}

int main(){
    cout<<tayl(3, 20);
}