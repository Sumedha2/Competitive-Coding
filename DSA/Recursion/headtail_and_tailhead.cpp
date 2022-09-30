#include <iostream>
using namespace std;

void tailhead(int n){
    if (n>0){
        //first executes while calling time
        cout<<n;
        //then calls function
        tailhead(n-1);
    }
}

void headtail(int n){
    if (n>0){
        //first calls functions
        headtail(n-1);
        //then executes after going back to function call while terminating/returning time
        cout<<n;
    }
}

int main(){
    int x=5;
    cout<<"using tail head function: ";
    //output gives descending order of numbers, in compliance with execution first
    tailhead(x);
    cout<<"\nusing headtail function: ";
    //output gives ascending order of numbers, in compliance with execution while return
    headtail(x);
    return 0;
}