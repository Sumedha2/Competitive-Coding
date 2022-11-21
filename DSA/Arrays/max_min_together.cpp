#include <iostream>
using namespace std;

int main()
{
    int a[20], n, max=0, min=0;
    cout<<"enter length of array: ";
    cin>>n;
    cout<<"enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        if(a[i]<min){
            min=a[i];
        }
        else if(a[i]>max){
            max=a[i];
        }
    }
    cout<<"max: "<<max<<" min: "<<min;
}