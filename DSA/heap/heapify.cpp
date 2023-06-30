#include <iostream>
using namespace std;

void swap(int a[], int i, int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

int ddelete(int a[], int n){
    int x=a[0];
    a[0]=a[n-1];

    int i=0, j=2*i+1;
    while(j<n-1){
        if(a[j]<a[j+1]){
            j++;
        }
        if(a[i]<a[j]){
            swap(a, i, j);
            i=j;
            j=2*i+1;
        }
        else{
            break;
        }
    }
    return x;
}

void heapify(int a[], int n){
    for(int i=(n/2)-1; i>=0; i--){
        int j=2*i+1;
        while(j<n-1){
            if(a[j]<a[j+1]){
                j++;
            }
            if(a[i]<a[j]){
                swap(a, i, j);
                i=j;
                j=2*i+1;
            }
            else{
                break;
            }
        }
    }
}

template<class t>
void print(t& v, int n, string s){
    cout<<s<<": [";
    for(int i=0; i<n; i++){
        cout<<v[i];
        if(i<n-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

int main(){
    int a[]={5, 10, 30, 20, 35, 40, 15};
    print(a, 7, "A");

    heapify(a, 7);
    print(a, 7, "heapified a");
    cout<<endl;

    int b[]={5, 10, 30, 20};
    print(b, 4, "b");

    heapify(b, 4);
    print(b, 4, "heapified b");
}