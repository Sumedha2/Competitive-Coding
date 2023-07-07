#include <iostream>
using namespace std;

void shell_sort(int a[], int n){
    for(int gap=n/2; gap>=1; gap/=2){
        for(int j=gap; j<n; j++){
            int temp=a[j];
            int i=j-gap;
            while(i>=0 && a[i]>temp){
                a[i+gap]=a[i];
                i=i-gap;
            }
            a[i+gap]=temp;
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
    shell_sort(a, n);
    cout<<"sorted array: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}