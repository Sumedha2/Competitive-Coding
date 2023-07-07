#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* n;
};

void insert(node** bins, int idx){
    node* temp= new node;
    temp->data=idx;
    temp->n=nullptr;
    if(bins[idx]==nullptr){
        bins[idx]=temp;
    }
    else{
        node* p=bins[idx];
        while(p->n!=nullptr){
            p=p->n;
        }
        p->n=temp;
    }
}

int ddelete(node** bins, int idx){
    node* p=bins[idx];
    bins[idx]=bins[idx]->n;
    int x=p->data;
    delete p;
    return x;
}

int findmax(int a[], int n){
    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
        if(a[i]>maxi){
            maxi=a[i];
        }
    }
    return maxi;
}

void bin_sort(int a[], int n){
    int maxi=findmax(a, n);
    node** bins=new node* [maxi+1];
    for(int i=0; i<=maxi; i++){
        bins[i]=nullptr;
    }
    for(int i=0; i<n; i++){
        insert(bins, a[i]);
    }
    int i=0, j=0;
    while(i<=maxi){
        while(bins[i]!=nullptr){
            a[j++]=ddelete(bins, i);
        }
        i++;
    }
    delete[] bins;
}

int main(){
    int a[100], n;
    cout<<"enter array size: ";
    cin>>n;
    cout<<"enter elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    bin_sort(a, n);
    cout<<"sorted array: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}