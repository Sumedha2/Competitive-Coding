#include <iostream>
using namespace std;

// power function using recursion
int powr(int m, int n){
    if (n==0){
        return 1;
    }
    if (n%2==0){
        return powr(m*m, n/2);
    }
    else{
        return m*powr(m*m, (n-1)/2);
    }
}

// power function using loop
int powl(int m, int n){
    if (n==0){
        return 1;
    }
    else{
        int i=1;
        int s=1;
        while (i<=n){
            s=s*m;
            i++;

        }
        return s;
    }
}

int main(){
    int rec=powr(2, 9);
    int loop=powl(2, 9);
    // both give same output
    cout<<rec<<endl<<loop;

}