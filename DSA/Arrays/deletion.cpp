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
    void deletee(int index){
        int x=a[index];
        for (int i=index; i<length-1; i++){
            a[i]=a[i+1];
        }
        length--;
    }
};

int main(){
    arrayy arr(10);
    arr.create();
    arr.display();
    int index;
    cout<<"enter index from which element is to be deleted: ";
    cin>>index;
    arr.deletee(index);
    cout<<"array after deletion: ";
    arr.display();

    return 0;
}