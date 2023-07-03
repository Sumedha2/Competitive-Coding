#include <iostream>
using namespace std;

void bubble_sort(int a[],int n){
    int flag;
    for(int i=0; i<n-1; i++){
        flag=0;
        for(int j=0; j<n-1-i; j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

int main(){
    int n, a[100];
    cout<<"enter size of array: ";
    cin>>n;
    cout<<"enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    bubble_sort(a, n);
    cout<<"sorted array: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}