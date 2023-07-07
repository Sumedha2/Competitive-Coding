#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int h){
    int i, j, k;
    i=l, j=mid+1, k=l;
    int b[h+1];
    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=h){
        b[k++]=a[j++];
    }
    for(int i=l; i<=h; i++){
        a[i]=b[i];
    }
}

// iterative 
void imerge_sort(int a[], int n){
    int p, i, l, mid, h;
    for(p=2; p<=n; p=p*2){
        for(i=0; i+p-1<n; i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(a, l, mid, h);
        }
    }
    if(p/2<n){
        merge(a, 0, p/2, n-1);
    }
}

// recursive
void rmerge_sort(int a[], int l, int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        rmerge_sort(a, l, mid);
        rmerge_sort(a, mid+1, h);
        merge(a, l, mid, h);
    }
}

int main(){
    int a[100], b[100], n;
    cout<<"enter size of array: ";
    cin>>n;
    cout<<"enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        b[i]=a[i];
    }
    imerge_sort(a, n);
    rmerge_sort(b, 0, n-1);
    cout<<"sorted using iterative method: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\nsorted using recursive method: ";
    for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
    }
}