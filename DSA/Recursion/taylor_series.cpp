#include <iostream>
using namespace std;

// taylor series using recursion
double tayr(int x, int n){
    // taking power as p and factorial as f
    static double p=1, f=1;
    double r;
    if (n==0){
        return 1;
    }
    else{
        r=tayr(x, n-1);
        p=p*x;
        f=f*n;
        return r+(p/f);
    }
}


// taylor series using for loop
double tayl(int x, int n){
    double s=1, p=1, f=1;
    for(int i=1; i<=n; i++){
        p*=x;
        f*=i;
        s+=(p/f);
    }
    return s;
}


int main(){
    // both give same output
    cout<<tayr(3, 20)<<endl<<tayl(3, 20);
}