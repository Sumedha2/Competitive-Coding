#include <iostream>
using namespace std;

void sorted_pair(int *a, int n, int k){
    int i=0, j=n-1;
    while(i<j){
        if(a[i]+a[j]==k){
            cout<<a[i]<<" "<<a[j]<<endl;;
            i++;
            j--;
        }
        else if(a[i]+a[j]<k){
            i++;
        }
        else{
            j--;
        }
    }
}

void unsorted_pair(int *a, int n, int k){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; i++){
            if(a[i]+a[j]==k){
                cout<<a[i]<<" "<<a[j]<<endl;
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

void hash_pair(int *a, int n, int k){
    int m=max(a, n); int h[100]={0};
    for(int i=0; i<m; i++){
        if(h[k-a[i]]!=0 && (k-a[i])>=0){
            cout<<a[i]<<" "<<k-a[i]<<endl;
        }
        h[a[i]]++;
    }
}

int main(){
    int a[20], n, k;
    cout<<"enter the length of array: ";
    cin>>n;
    cout<<"enter the array elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"enter sum: ";
    cin>>k;
    int ch;
    cout<<"1)Sorted Array \n2)Unsorted Array \n3)Sorted/Unsorted Array Using Hash\n";
    cin>>ch;
    if(ch==1){
        sorted_pair(a, n, k);
    }
    else if(ch==2){
        unsorted_pair(a, n, k);
    }
    else{
        hash_pair(a, n, k);
    }
}