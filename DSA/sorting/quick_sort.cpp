#include <iostream>
using namespace std;

int partition(int a[], int l, int h){
    int pivot=a[l];
    int i=l, j=h;
    do{
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j){
            swap(a[i], a[j]);
        }
    }while(i<j);
    swap(a[l], a[j]);
    return j;
}

void quick_sort(int a[], int l, int h){
    if(l<h){
        int p=partition(a, l, h);
        quick_sort(a, l, p);
        quick_sort(a, p+1, h);
    }
}

int main(){
    int a[100], n;
    cout<<"enter array size: ";
    cin>>n;
    cout<<"enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    quick_sort(a, 0, n);
    cout<<"sorted array: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}