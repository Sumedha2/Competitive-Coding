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

// function to reverse array using an auxilliary array
void rev(){
    int b[length];
    for(int i=length-1, j=0; i>=0; i--, j++){
        b[j]=a[i];
    }
    for(int i=0; i<length; i++){
        a[i]=b[i];
    }
}

// re reversing array without auxilliary array
void rerev(){
    for(int i=0, j=length-1; i<j; i++, j--){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}


int main(){
    cout<<"enter the number of elements in the array: ";
    cin>>length;
    cout<<"enter the array elements: ";
    for(int i=0; i<length; i++){
        cin>>a[i];
    }
    display();
    cout<<"reversed array using auxilliary array: "<<endl;
    rev();
    display();
    cout<<"reversed array without using auxilliary array: "<<endl;
    rerev();
    display(); 
}