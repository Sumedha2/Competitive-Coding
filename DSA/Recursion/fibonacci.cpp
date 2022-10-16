#include <iostream>
using namespace std;

// fibonacci sequence using recursion
int fib(int n){
    if (n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fib(n-2)+fib(n-1);
    }
}

// fibonacci sequence using loop
int fibl(int n){
    if (n==0||n==1){
        return n;
    }
    else{
        int f=0, s=1, c=2, su=1;
        while(c<n){
            su=f+s;
            f=s;
            s=su;
            c++;
        }
        return su;
    }
}

int main(){
    int n=10;
    // output using recursion
    for (int i=0; i<=n; i++){
        cout<<fib(i)<<" ";
    }
    cout<<endl;
    // output using loop
    for (int i=0; i<=n; i++){
        cout<<fib(i)<<" ";
    }
    // both give same output
}