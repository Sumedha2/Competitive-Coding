#include <iostream>
using namespace std;

void display(int *a, int length){
    cout<<"the array is: "<<endl;
    for(int i=0; i<length; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

bool sorted(int *a, int length){
    for(int i=0; i<length-1; i++){
        if(a[i]>a[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    int length, a[10];
    cout<<"enter the number of elements in array: ";
    cin>>length;
    cout<<"enter the array elements: ";
    for(int i=0; i<length; i++){
        cin>>a[i];
    }
    display(a, length);
    cout<<"is the array sorted? ";
    cout<<sorted(a, length);
}