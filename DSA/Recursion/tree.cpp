#include <iostream>
using namespace std;

void fun(int n){
    if (n>0){
        cout<<n<<endl;
        fun(n-1);
        // calls the recursive function once again, hance tree recursion
        fun(n-1);
    }
}

// tree recursion
// space occupied: height of stack=n+1 as activation records are cancelled after calling function
// hence, space complexity: O(n)
// time taken: calls at each activation level= 2^0+2^1+....2^n=2^(n+1)-1
// hence time complexity: O(2^n)

int main(){
    int n=4;
    fun(4);
    // output will be 4, 3, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 2, 1, 1
    // frequency of 4=2^0
    // frequency of 3=2^1
    // frequency of 2=2^2
    // frequency of 1=2^3
}