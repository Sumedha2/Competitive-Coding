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
    last->next=head;
    return head;
}

void display(node* p, node* head){
    if(head==NULL){
        return;
    }
    do{
        cout<<p->data<<" -> ";
        p=p->next;
    }while(p!=head);
}


void fdelete(node*& f, int pos){
    node* p;
    node* q;
    // for head node
    if(pos==0){
        p=f;
        while(p->next!=f){
            p=p->next;
        }
        int x=f->data;
        if(p==f){
            delete f;
            f=NULL;
        }
        else{
            p->next=f->next;
            delete f;
            f=p->next;
        }
    }
    // for any other position
    else{
        p=f;
        for(int i=0; i<pos-1; i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        int x=q->data;
        delete q;
    }
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    node* p=create(a, 5);
    display(p, p);
    cout<<endl;
    fdelete(p, 1);
    display(p, p);
}