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
    tail->next=head;
    return head;
}


void display(node* p){
    node* s=p;
    do{
        cout<<p->data<<" -> ";
        p=p->next;
    }while(p!=s);
}

void insert(node*& s, int x, int pos){
    node* p=s;
    node* t= new node;
    t->data=x;
    if(pos==0){
        node* last=new node;
        last=p->prev;
        t->next=p;
        t->prev=last;
        last->next=t;
        p->prev=t;
        p=t;
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
    node* p=create(a, 5);
    display(p);
    cout<<endl;
    insert(p, 9, 1);
    display(p);
}