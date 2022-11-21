#include <iostream>
using namespace std;

void unsorted(int *a, int n){
    for(int i=0; i<n-1; i++){
        int c=1;
        if(a[i]!=-1){
            for(int j=i+1; j<n; j++){
                if(a[i]==a[j]){
                    c++;
                    a[j]=-1;
                }
            }
            if(c>1){
                cout<<a[i]<<" repeats "<<c<<" times "<<endl;
            }
        }
    }
}

int max(int *a, int n){
    int max=a[0];
    for(int i=0; i<n; i++){
        if (a[i]>max){
            max=a[i];
        }
    }
    return max;
}

void unsorted_hash(int *a, int n){
    int m=max(a, n); int h[100]={0};
    for(int i=0; i<n; i++){
        h[a[i]]++;
    }
    for(int i=0; i<=m; i++){
        if(h[i]>1){
            cout<<i<<" repeats "<<h[i]<<" times"<<endl;
        }
    }
}

int main(){
    int a[20], n;
    cout<<"enter length of unsorted array: ";
    cin>>n;
    cout<<"enter array elements: ";
    for(int i=0; i<n ; i++){
        cin>>a[i];
    }
    cout<<"1) Using hash table \n2) Without using hash table ";
    int ch;
    cin>>ch;
    if(ch==1){
        cout<<"using hash tables: "<<endl;
        unsorted_hash(a, n);
    }
    else{
        cout<<"elements with duplicates are: "<<endl;
        unsorted(a, n);
    }
}