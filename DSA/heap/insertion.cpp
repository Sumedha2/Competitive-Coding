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

template <class t>
void print(t& v, int n){
    cout<<"max heap: [";
    for(int i=0; i<n; i++){
        cout<<v[i];
        if(i<n-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

int main(){
    int a[]={20, 30, 8, 60, 5, 9};
    inserta(a, 6);
    print(a, 6);

    vector<int> v= {20, 30, 8, 60, 5, 9};
    print(v, v.size());
    v.reserve(15);
    inserts(v, 50);
    print(v, v.size());
    return 0;
}