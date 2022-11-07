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
    void insert(int index, int x){
        for (int i=length; i>index; i--){
            a[i]=a[i-1];
        }
        a[index]=x;
        length++;
    }

};

int main(){
    arrayy arr(10);
    arr.create();
    arr.display();
    arr.insert(5, 4);
    arr.display();

    return 0;
}