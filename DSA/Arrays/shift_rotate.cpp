#include <iostream>
using namespace std;

int length, a[10];

void display(){
    cout<<"the array is: "<<endl;
    for(int i=0; i<length; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// function for left shift in array
void left_shift(){
    for(int i=0; i<length-1; i++){
        a[i]=a[i+1];
    }
    a[length-1]=0;
}

// function for left rotation in array
void left_rotate(){
    int temp=a[0];
    for(int i=0; i<length-1; i++){
        a[i]=a[i+1];
    }
    a[length-1]=temp;
}


int main(){
    cout<<"enter the number of elements in the array: ";
    cin>>length;
    cout<<"enter the array elements: ";
    for(int i=0; i<length; i++){
        cin>>a[i];
    }
    display();
    cout<<"array after left shift: "<<endl;
    left_shift();
    display();
    cout<<"array after left rotation: "<<endl;
    left_rotate();
    display(); 
}