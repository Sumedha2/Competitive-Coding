#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void display(node* p){
    while(p){
        cout<<p->data<<" -> ";
        p=p->next;
    }
}

bool sorted(node* p){
    int x=INT_MIN;
    node* s=p;
    while(s){
        if(s->data<x){
            return false;
        }
        x=s->data;
        s=s->next;
    }
    return true;
}

int main(){
    int a[]={2, 1, 3, 4, 5, 6};
    node* head= new node;
    node* temp;
    node* last;
    head->data=a[0];
    head->next=nullptr;
    last=head;
    for(int i=1; i<sizeof(a)/sizeof(a[0]); i++){
        temp=new node;
        temp->data=a[i];
        temp->next=nullptr;
        last->next=temp;
        last=temp;
    }
    node* p=head;
    cout<<sorted(p);
}