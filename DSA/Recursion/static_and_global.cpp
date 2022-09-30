#include <iostream>
using namespace std;

int fun(int n){
    if (n>0){
        return fun(n-1)+n;
    }
    return 0;
}

//introducing a static integer
int fun_static(int n){
    static int x=0;
    if (n>0){
        x++;
        //instead of adding recursive variables, it adds the static variable to recursive function calls 
        return fun_static(n-1)+x;
    }
    return 0;
}

//introducing a global variable 
int t=0;
int fun_global(int n){
    if (n>0){
        t++;
        //instead of adding recursive variables, it adds the global variable to recursive function calls 
        return fun_global(n-1)+t;
    }
    return 0;
}

int main(){
    int a=5;
    int fun_=fun(a);
    int static_=fun_static(a);
    int global_=fun_global(a);
    //output is 15, as 1+2+3+4+5=15
    cout<<"recursive function: "<<fun_<<'\n';
    //output is 25, as 5+5+5+5+5=25
    cout<<"recursive function with static variable: "<<static_<<'\n';
    //output is 25, as 5+5+5+5+5
    cout<<"recursive function with global variable: "<<global_<<'\n';
}