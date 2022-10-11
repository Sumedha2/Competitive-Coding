// tail recursion: where the recursive call is the last statement in function
// every task performed at calling time, nothing at returning time

#include <iostream>
using namespace std;

// simple tail recursion function:
// time complexity is O(n)
// space complexity is also O(n)- utilises stack
void fun(int n){
    if (n>0){
        cout<<n<<endl;
        fun(n-1);
    }
}

// loop with the same task as recursion function
// time complexity is O(n)
// space complexity is O(1) as it doesnt call itself
void fun1(int n){
    while (n>0){
        cout<<n<<endl;
        n--;
    }
}

int main(){
    cout<<"using recursive function: "<<endl;
    fun(3);
    cout<<"using loop: "<<endl;
    fun1(3);
}