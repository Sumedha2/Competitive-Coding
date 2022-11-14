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

void insert_sorted(int *a, int x, int length){
    int i=length-1;
    while(a[i]>x){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=x;
}

int main(){
    cout<<"enter the number of elements in the array: ";
    cin>>length;
    cout<<"enter the elements of the sorted array: ";
    for(int i=0; i<length; i++){
        cin>>a[i];
    }
    display();
    cout<<"enter the element to be inserted: ";
    int x;
    cin>>x;
    cout<<"the new array is: "<<endl;
    insert_sorted(a, x, length);
    display();
}