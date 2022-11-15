#include <iostream>
using namespace std;

void display(int *a, int length){
    cout<<"the array is: ";
    for(int i=0; i<length; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void neg_pos_segregate(int *a, int length){
    int i=0, j=length-1;
    while(i<j){
        while(a[i]<0){i++;}
        while(a[j]>=0){j--;}
        if(i<j){swap(&a[i], &a[j]);}
    }
    }

int main(){
    int a[10], length;
    cout<<"enter the length of the array: ";
    cin>>length;
    cout<<"now enter the elements of the array: ";
    for(int i=0; i<length; i++){
        cin>>a[i];
    }
    display(a, length);
    cout<<"after sorting the array with shifting negative elements to the left and positive to the right: "<<endl;
    neg_pos_segregate(a, length);
    display(a, length);
}