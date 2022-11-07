#include <iostream>
using namespace std;

class arrayy{
private:
    int* a;
    int size;
    int length;

public:
    arrayy(int size){
        this->size=size;
        a= new int [size];
    }

    void create(){
        cout<<"enter number of elements in array: ";
        cin>>length;
        cout<<"enter elements of array: ";
        for(int i=0; i<length; i++){
            cin>>a[i];
        }
    }
    void display(){
        cout<<"Array elements are: ";
        for (int i=0; i<length; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void linear_search(int key){
    for (int i=0; i<length; i++){
        if (key==a[i]){
            cout<<i;
        }
    }

    // to improve repeated search in linear method, we can either use transposition or move to head
    // in transposition, the searched element is swaped with the previous element to give faster results next time
    // in move to head/front, the searched element is swaped with the first element of array
}

};

int main(){
    arrayy arr(10);
    arr.create();
    arr.display();
    cout<<"enter element to be searched: ";
    int key;
    cin>>key;
    cout<<"index of "<<key<<" is: ";
    arr.linear_search(key);
}