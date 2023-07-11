#include <iostream>
#define size 10
#define prime 7
using namespace std;


int hashh(int key){
    return key%size;
}
int prime_hash(int key){
    return prime-(key%prime);
}
int double_hash(int h[], int key){
    int idx=hashh(key);
    int i=0;
    while(h[(idx+i*prime_hash(idx))%size]!=0){
        i++;
    }
    return (idx+i*prime_hash(idx))%size;
}
void insert(int h[], int key){
    int idx=hashh(key);
    if(h[idx]!=0){
        idx=double_hash(h, key);
    }
    h[idx]=key;
}
int search(int h[], int key){
    int idx=hashh(key);
    int i=0;
    while(h[(idx+i*prime_hash(idx))%size]!=key){
        i++;
        if(h[(idx+i*prime_hash(idx))%size]==0){
            return -1;
        }
    }
    return (idx+i*prime_hash(idx))%size;
}

int main(){
    int a[100], n, ht[10]={0};
    cout<<"enter array size: ";
    cin>>n;
    cout<<"enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
        insert(ht, a[i]);
    }
    cout<<"enter key to search: ";
    int k;
    cin>>k;
    int index=search(ht, k);
    cout<<"key found at: "<<index<<endl;
}