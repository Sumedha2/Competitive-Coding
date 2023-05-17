#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
node* head=new node;

node* create(int* a, int size){
    node* last;
    node* temp;
    head->data=a[0];
    head->next=nullptr;
    last=head;
    for(int i=1; i<size; i++){
        temp=new node;
        temp->data=a[i];
        temp->next=nullptr;
        last->next=temp;
        last=temp;
    }
    last->next=head;
    return head;
}


int main(){
    int a[]={1, 2, 3, 4, 5};
    node* p=create(a, 5);
}