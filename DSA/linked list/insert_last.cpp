#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void display(node* n){
    while(n){
        cout<<n->data<<" -> ";
        n=n->next;
    }
}

void insertlast(int x, node*& p){
    node* t= new node;
    node *last= p;
    t->data=x;
    t->next=NULL;
    if(p==NULL){
        p=t;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=t;
    return;
}

int main(){
    node* head=new node;
    head->data=1;
    head->next=nullptr;
    insertlast(3, head);
    insertlast(4, head);
    display(head);
}
