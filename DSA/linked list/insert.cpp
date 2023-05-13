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

void insert(int pos, int x, node*& p){
    node* t;
    node* s;
    // inserting in the beginning
    if(pos==0){
        t=new node;
        t->data=x;
        t->next=p;
        p=t;
    }
    // inserting in the middle
    else if(pos>0){
        s=p;
        for(int i=0; i<pos-1&&s; i++){
            s=s->next;
        }
        if(s){
            t= new node;
            t->data=x;
            t->next=s->next;
            s->next=t;
        }
        p=s;
    }
}

int main(){
    int a[]={4, 3, 6, 2, 5};
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
    // inserting in the middle 
    insert(1, 1, p);
    // inserting at the beginning
    insert(0, 2, p);
    display(p);
    return 0;

}