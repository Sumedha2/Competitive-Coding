#include <iostream>
using namespace std;

// factorial using recursion
int factr(int n){
    if (n==0){
        return 1;
    }
    else{
        return factr(n-1)*n;
    }
}

// factorial using loop
int factl(int n){
    if (n==0){
        return 1;
    }
    else{
        int s=1;
        for (int i=1; i<=n; i++){
            s=s*i;
        }
        return s;
    }
}

int main(){
    // using recursion
    int rec=factr(5);
    // using loop
    int loop=factl(5);
    cout<<rec<<endl<<loop;
    // both give output of 120
}