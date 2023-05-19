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

void insert(node*& head, int pos, int x){
    node* p=head;
    node* t=new node;
    t->data=x;
    if(pos==0){
        t->prev=nullptr;
        t->next=head;
        head->prev=t;
        head=t;
    }
    else{
        for(int i=0; i<pos-1; i++){
            p=p->next;
        }
        t->prev=p;
        t->next=p->next;
        if(p->next){
            p->next->prev=t;
        }
        p->next=t;
    }
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    node* head=create(a, 5);
    display(head);
    insert(head, 1, 8);
    display(head);
    insert(head, 0, 9);
    display(head);
}