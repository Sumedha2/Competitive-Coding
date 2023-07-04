#include <iostream>
using namespace std;

void insertion_sort(int a[], int n){
    for(int i=1; i<n; i++){
        int j=i-1, x=a[i];
        while(j>-1 && a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

int main(){
    int a[100], n;
    cout<<"enter size of array: ";
    cin>>n;
    cout<<"enter elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    insertion_sort(a, n);
    cout<<"sorted array: "<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}