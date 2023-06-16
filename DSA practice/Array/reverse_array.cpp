#include <iostream>
using namespace std;

void swap(int* x, int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void reverse(int* arr, int size){
    int f=0; int l=size-1, t=int(size/2);
    for(int i=0; i<=t; i++){
        swap(&arr[f], &arr[l]);
        f++;
        l--;
    }
}

int main(){
    int size;
    cout<<"enter size of array: ";
    cin>>size;
    int arr[size];
    cout<<"enter elements: ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    reverse(arr, size);
    cout<<"reversed array: ";
    for(int i=0; i<size; i++){
        cout<<arr[i];
    }
}