#include <iostream>
using namespace std;

int single_sorted(int *a, int n){
    int sum=0, l=a[n-1];
    for(int i=0; i<n; i++){
        sum+=a[i];
    }
    int s=(l*(l+1))/2;
    return s-sum;
}

void multiple(int *a, int n){
    int l=a[0], h=a[n-1];
    int diff=l-0;
    for(int i=0; i<n; i++){
        if(a[i]-i!=diff){
            while (diff<a[i]-i){
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }
}

void unsorted(int *a, int n){
    int ha[20]={0}, l=a[0], h=a[n-1];
    for(int i=0; i<n; i++){
        ha[a[i]]++;
    }
    for(int i=l; i<=h; i++){
        if(ha[i]==0){
            cout<<i<<" ";
        }
    }
}

int main(){
    int c, a[20], n;
    cout<<"Menu: \n1) Sorted array, single missing element \n2) Sorted array, multiple missing elements \n3) Unsorted array\n";
    cout<<"Choose option: ";
    cin>>c;
    cout<<"Input array length: ";
    cin>>n;
    cout<<"Input array elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    if (c==1){
        cout<<"Missing element is: "<<single_sorted(a, n)<<endl;
    }
    else if(c==2){
        cout<<"Missing elements are: ";
        multiple(a, n);
        cout<<endl;
    }
    else{
        cout<<"Missing element(s) is/are: ";
        unsorted(a, n);
        cout<<endl;
    }
}