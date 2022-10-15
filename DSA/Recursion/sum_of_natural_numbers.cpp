#include <iostream>
using namespace std;

// sum of first n natural numbers using recursion
int sumr(int n){
    if (n==0){
        return 0;
    }
    else{
        return sumr(n-1)+n;
    }
}

// sum of first n natural numbers using loop
int suml(int n){
    int s=0;
    for (int i=1; i<=n; i++){
        s=s+i;
    }
    return s;
}

// sum of first n natural numbers using direct formula 
int sumd(int n){
    return n*(n+1)/2;
}

int main(){
    // using recursion
    int rec=sumr(10);
    cout<<rec<<endl;
    // using loop
    int loop=suml(10);
    cout<<loop<<endl;
    // using formula
    int dir=sumd(10);
    cout<<dir<<endl;
    // all 3 give same output of 55
}