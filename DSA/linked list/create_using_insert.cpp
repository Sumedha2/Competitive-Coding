#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void display(node *n){
    while(n){
        cout<<n->data<<" -> ";
        n=n->next;
    }
}

void insert(int pos, int x, node*& p){
    node* t;
    node* s;
    if(pos==0){
        t=new node;
        t->data=x;
        t->next=p;
        p=t;
    }
    else{
        s=p;
        for(int i=0; i<pos-1&&s; i++){
            s=s->next;
        }
        if(s){
            t=new node;
            t->data=x;
            t->next=s->next;
            s->next=t;
        }
        p=s;
    }
}

int main(){
    node* head=new node;
    insert(0, 1, head);
    insert(0, 2, head);
    insert(0, 3, head);
    insert(0, 4, head);
    insert(1, 5, head);
    display(head);
    return 0;
}