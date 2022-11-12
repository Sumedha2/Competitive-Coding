#include <iostream>
using namespace std;
int length, a[20];
void display(){
    cout<<"the elements are: ";
    for(int i=0; i<length; i++){
        cout<<a[i]<<" '";
    }
    cout<<endl;
}

// binary search code
int bin_search(int key){
    int l=0, h=length;
    while(l<=h){
        int mid=(l+h)/2;
        if (key==a[mid]){
            return mid;
        }
        else if (key<a[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

// binary search using recursion
int rbin_search(int l, int h, int key){
    if (l<=h){
        int mid=(l+h)/2;
        if (key==a[mid]){
            return mid;
        }
        else if (key<a[mid]){
            return rbin_search(l, mid-1, key);
        }
        else{
            return rbin_search(mid+1, h, key);
        }
    }
    return -1;
}

int main(){
    cout<<"enter the number of elements: ";
    cin>>length;
    cout<<"enter the elements: ";
    for(int i=0; i<length; i++){
        cin>>a[i];
    }
    int key;
    cout<<"enter element to be searched: ";
    cin>>key;
    cout<<"through binary search: "<<bin_search(key)<<endl;
    int l=0, h=length;
    cout<<"through recursive binary search: "<<rbin_search(l, h, key)<<endl;
}