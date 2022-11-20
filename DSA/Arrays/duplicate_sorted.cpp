#include <iostream>
using namespace std;


void find_sorted(int *a, int n){
    int last=0;
    for(int i=0; i<n; i++){
        if (a[i]==a[i+1]&&a[i]!=last){
            cout<<a[i]<<" ";
            last=a[i];
        }
    }
    cout<<endl;
}

void count_sorted(int *a, int n){
    for(int i=0; i<n-1; i++){
        if(a[i]==a[i+1]){
            int j=i+1;
            while(a[j]==a[i]){
                j++;
            }
            cout<<a[i]<<" appears "<<j-i<<" times "<<endl;
            i=j-1;
        }
    }
}

void sorted_hash(int *a,int n){
    int h[100]={0};
    for(int i=0; i<n; i++){
        h[a[i]]++;
    }
    for(int i=0; i<=a[n-1]; i++){
        if(h[i]>1){
            cout<<i<<" repeats "<<h[i]<<" times "<<endl;
        }
    }
}


int main(){
    int a[20], n;
    cout<<"enter number of elements in your sorted array: ";
    cin>>n;
    cout<<"enter the elements of your array: ";
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    cout<<"the following elements have duplicates: ";
    find_sorted(a, n);
    count_sorted(a, n);
    cout<<"using hash table: "<<endl;
    sorted_hash(a, n);
}