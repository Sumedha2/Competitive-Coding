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

// delete first element
void ddelete(node*& p){
    node* s=p;
    p=p->next;
    int x=s->data;
    delete s;
}

// delete from given position
void pdelete(node*& first, int pos){
    node* p=first;
    node* q=NULL;
    for(int i=0; i<pos-1; i++){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    int x=p->data;
    delete p;
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
    display(p); 
    ddelete(p);
    pdelete(p, 2);
    cout<<endl;
    display(p);
}