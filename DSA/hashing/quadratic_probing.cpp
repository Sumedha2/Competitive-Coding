#include <iostream>
#define size 10
using namespace std;


int hashh(int key){
    return key%size;
}
int quadratic_probing(int h[], int key){
    int idx=hashh(key);
    int i=0;
    while(h[(idx+i*i)%size]!=0){
        i++;
    }
    return (idx+i*i)%size;
}
void insert(int h[], int key){
    int idx=hashh(key);
    if(h[idx]!=0){
        idx=quadratic_probing(h, key);
    }
    h[idx]=key;
}
int search(int h[], int key){
    int idx=hashh(key);
    int i=0;
    while(h[(idx+i*i)%size]!=key){
        i++;
        if(h[(idx+i*i)%size]==0){
            return -1;
        }
    }
    return (idx+i*i)%size;
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