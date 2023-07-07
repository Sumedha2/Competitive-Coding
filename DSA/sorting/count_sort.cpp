#include <iostream>
using namespace std;

int findmax(int a[], int n){
    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
        if(maxi<a[i]){
            maxi=a[i];
        }
    }
    return maxi;
}

void count_sort(int a[], int n){
    int maxi, *c;
    maxi=findmax(a, n);
    c=new int[maxi+1];
    for(int i=0; i<=maxi; i++){
        c[i]=0;
    }
    for(int i=0; i<n; i++){
        c[a[i]]++;
    }
    int i=0, j=0;
    while(i<=maxi){
        if(c[i]>0){
            a[j++]=i;
            c[i]--;
        }
        else{
            i++;
        }
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
    count_sort(a, n);
    cout<<"sorted array: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}