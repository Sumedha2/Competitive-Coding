#include <iostream>
using namespace std;


void merge(int *a, int *b, int m, int n, int *c){
    int i=0, j=0, k=0;
    while(i<m && j<n){
        if (a[i]<b[j]){
            c[k++]=a[i++];
        }
        else{
            c[k++]=b[j++];
        }
    }
    while(i<m){
       c[k++]=a[i];
       i++; 
    }
    while(j<n){
       c[k++]=b[j];
       j++; 
    }
    cout<<"merged array is: ";
    for(int i=0; i<(m+n); i++){
        cout<<c[i]<<" ";
    }
}

int main(){
    int a[10], b[10], c[20];
    int m, n;
    cout<<"enter the number of elements in 'a' array: ";
    cin>>m;
    cout<<"enter the elements of 'a' array: ";
    for(int i=0; i<m; i++){
        cin>>a[i];
    }
    cout<<"enter the number of elements in 'b' array: ";
    cin>>n;
    cout<<"enter the elements of 'b' array: ";
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    merge(a, b, m, n, c);
}