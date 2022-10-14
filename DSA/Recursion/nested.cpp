#include <iostream>
using namespace std;


// nested recursion
// call within a call

int fun(int n){
    if (n>100){
        return n-10;
    }
    else{
        return fun(fun(n+11));
    }
}

int main(){
    int n=25;
    int ans=fun(n);
    cout<<ans<<"  ";
    // output: 91
}