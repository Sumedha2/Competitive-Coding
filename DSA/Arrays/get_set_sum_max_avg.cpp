#include <iostream>
using namespace std;

int length, a[20];
void display(){
    cout<<"the elements are: "<<endl;
    for (int i=0; i<length; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// get method to print an element if we know the index
int get(int index){
    if(index>=0 && index<length){
        return a[index];
    }
    return -1;
}

// set method to overwrite a value given the index and new value
void set(int index2, int x){
    if (index2>=0 && index2<length){
        a[index2]=x;
    }
}

// function to get the biggest element in array
int maxi(){
    int max=a[0];
    for(int i=1; i<length; i++){
        if (a[i]>max){
            max=a[i];
        }
    }
    return max;
}

// function to get smallest element in array
int mini(){
    int min=a[0];
    for(int i=1; i<length; i++){
        if (a[i]<min){
            min=a[i];
        }
    }
    return min;
}

// function to get the sum of array
int tot(){
    int total=0;
    for (int i=0; i<length; i++){
        total+=a[i];
    }
    return total;
}

// recursive function to find sum of array
int rsum(int *a, int length){
    if (length<0){
        return 0;
    }
    else{
        return rsum(a, length-1)+a[length];
    }
}

// funtion to find average 
float avg(){
    int sumi=0;
    for(int i=0; i<length; i++){
        sumi+=a[i];
    }
    return (float)sumi/length;
}

int main(){
    cout<<"enter the number of elements: ";
    cin>>length;
    cout<<"enter the array elements: ";
    for (int i=0; i<length; i++){
        cin>>a[i];
    }
    display();
    cout<<"index of element to find? ";
    int index;
    cin>>index;
    cout<<"the element is: "<<get(index)<<endl;
    int index2, x;
    cout<<"enter the index of element to overwrite and the new element: ";
    cin>>index2>>x;
    set(index2, x);
    cout<<"the new array is: ";
    display();
    cout<<"the biggest element of the array is: "<<maxi()<<endl;
    cout<<"the smallest element of the array is: "<<mini()<<endl;
    cout<<"the sum of the array is: "<<tot()<<endl;
    cout<<"sum using recursive function: "<<rsum(a, length)<<endl;
    cout<<"the average of the array is: "<<avg()<<endl;

}