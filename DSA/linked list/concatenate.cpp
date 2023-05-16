#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

node* create(int* a, int size){
    node* head= new node;
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
    return head;
}

void display(node* p){
    while(p){
        cout<<p->data<<" -> ";
        p=p->next;
    }
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    int b[]={6, 7, 8, 9, 10};
    node* p=create(a, 5);
    node* q=create(b, 5);
    // to concatenate
    node* s=p;
    while(s->next){
        s=s->next;
    }
    s->next=q;
    q=nullptr;
    display(p);
}