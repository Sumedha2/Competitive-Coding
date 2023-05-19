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

void ddelete(node*& head, int pos){
    node* p=head;
    if(pos==0){
        head=head->next;
        if(head){
            head->prev=nullptr;
        }
        delete p;
    }
    else{
        for(int i=1; i<pos; i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        }
        delete p;
    }
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    node* head=create(a, 5);
    display(head);
    ddelete(head, 4);
    display(head);
    ddelete(head, 0);
    display(head);
}