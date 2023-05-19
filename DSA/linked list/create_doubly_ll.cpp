#include <iostream>
using namespace std;

class node{
    public:
    node* prev;
    int data;
    node* next;
};

node* create(int* a, int size){
    node* head=new node;
    head->prev=NULL;
    head->data=a[0];
    head->next=NULL;
    node* tail=head;
    for(int i=1; i<size; i++){
        node* t=new node;
        t->prev=tail;
        t->data=a[i];
        t->next=tail->next;
        tail->next=t;
        tail=t;
    }
    return head;
}

void display(node* head){
    node* p=head;
    while(p){
        cout<<p->data;
        p=p->next;
        if(p){
            cout<<" <-> ";
        }
    }
    cout<<endl;
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    node* p=create(a, 5);
    display(p);
}