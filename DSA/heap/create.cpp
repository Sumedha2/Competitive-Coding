#include <iostream>
#include <vector>

using namespace std;

void inserta(int a[], int n){
    int i=n, temp=a[n];
    while(i>0 && temp>a[i%2==0?(i/2)-1:i/2]){
        a[i]=a[i%2==0?(i/2)-1:i/2];
        i=i%2==0?(i/2)-1:i/2;
    }
    a[i]=temp;
}

void inserts(vector<int>& v, int key){
    auto i=v.size();
    v.push_back(key);
    while(i>0 && key>v[i%2==0?(i/2)-1:i/2]){
        v[i]=v[i%2==0?(i/2)-1:i/2];
        i=i%2==0?(i/2)-1:i/2;
    }
    v[i]=key;
}

void createheap(vector<int>& v, int a[], int n){
    for(int i=0; i<n; i++){
        inserts(v, a[i]);
    }
}

void createheap(int a[], int n){
    for(int i=0; i<n; i++){
        inserta(a, i);
    }
}

template <class t>
void print(t& v, int n, char c){
    cout<<c<<": [";
    for(int i=0; i<n; i++){
        cout<<v[i];
        if(i<n-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

int main(){
    cout<<"create heap: "<<endl;
    int a[]={20, 30, 8, 60, 5, 9};
    print(a, 6, 'a');

    vector<int> v;
    createheap(v, a, 6);
    print(v, v.size(), 'v');

    cout<<"inplace insert"<<endl;
    createheap(a, 6);
    print(a, 6, 'a');

    return 0;
}