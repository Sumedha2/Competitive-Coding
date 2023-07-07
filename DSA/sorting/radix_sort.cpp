#include <iostream>
#include <cmath>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
void initialize_bins(node** p, int n){
    for(int i=0; i<n; i++){
        p[i]=nullptr;
    }
}
void insert(node** bins, int data, int idx){
    node* temp=new node;
    temp->data=data;
    temp->next=nullptr;
    if(bins[idx]==nullptr){
        bins[idx]=temp;
    }
    else{
        node* p=bins[idx];
        while(p->next!=nullptr){
            p=p->next;
        }
        p->next=temp;
    }
}
int ddelete(node** bins, int idx){
    node* p=bins[idx];
    bins[idx]=bins[idx]->next;
    int x=p->data;
    delete p;
    return x;
}
int get_bin_index(int x, int idx){
    return (int)(x/pow(10, idx))%10;
}
int count_digit(int x){
    int c=0;
    while(x!=0){
        x=x/10;;
        c++;
    }
    return c;
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

void radix_sort(int a[], int n){
    int maxi=findmax(a, n);
    int pass=count_digit(maxi);
    node** bins=new node* [10];
    initialize_bins(bins, 10);
    for(int j=0; j<pass; j++){
        for(int i=0; i<n; i++){
            int binidx=get_bin_index(a[i], j);
            insert(bins, a[i], binidx);
        }
        int i=0, k=0;
        while(i<10){
            while(bins[i]!=nullptr){
                a[k++]=ddelete(bins, i);
            }
            i++;
        }
        initialize_bins(bins, 10);
    }
    delete [] bins;
}

int main(){
    int a[100], n;
    cout<<"enter array size: ";
    cin>>n;
    cout<<"enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    radix_sort(a, n);
    cout<<"sorted array: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}