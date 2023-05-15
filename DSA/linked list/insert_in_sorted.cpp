#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void display(node *p){
    while(p){
        cout<<p->data<<" -> ";
        p=p->next;
    }
}

void insert(int x, node*& p){
    node* s=p;
    node *r=NULL;
    while(s&&s->data<x){
        r=s;
        s=s->next;
    }
    node* t= new node;
    t->data=x;
    t->next=r->next;
    r->next=t;
}

int main(){
    int a[]={2, 4, 6, 8};
    node* head= new node;
    node* temp;
    node* last;
    head->data=a[0];
    head->next=nullptr;
    last=head;
    for(int i=1; i<sizeof(a)/sizeof(a[0]); i++){
        temp= new node;
        temp->data=a[i];
        temp->next=nullptr;
        last->next=temp;
        last=temp;
    }
    node* p=head;
    insert(5, p);
    display(p);
}