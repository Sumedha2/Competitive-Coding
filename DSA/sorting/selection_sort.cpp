#include <iostream>
using namespace std;

void selection_sort(int a[], int n){
    int i, j, k;
    for(i=0; i<n-1; i++){
        for(j=k=i; j<n; j++){
            if(a[j]<a[k]){
                k=j;
            }
        }
        swap(a[i], a[k]);
    }
}

int main(){
    int a[100], n;
    cout<<"enter size of array: ";
    cin>>n;
    cout<<"enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    selection_sort(a, n);
    cout<<"sorted array: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}