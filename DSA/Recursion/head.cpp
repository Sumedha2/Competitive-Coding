// head recursion: function call has to be the first statement
// can't be easily converted to loop


#include <iostream>
using namespace std;
// simple head recursion function:
void fun(int n){
    if(n>0){
        fun (n-1);
        cout<<n<<endl;
    }
}

// same task with loop:
void fun1(int n){
    int i=1;
    while (i<=n){
        cout<<i<<endl;
        i++;
    }
}

int main(){
    cout<<"using head recursion: "<<endl;
    fun(5);
    cout<<"using loop: "<<endl;
    fun1(5);
}