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

void insert(node** first, int pos, int x){
    node* t;
    node* p;
    if(pos==0){
        t=new node;
        t->data=x;
        if(*first==NULL){
            *first=t;
            (*first)->next=*first;
        }
        p=*first;
        while(p->next!=*first){
            p=p->next;
        }
        p->next=t;
        t->next=*first;
        *first=t;
    }
    else{
        p=*first;
        for(int i=0; i<pos-1; i++){
            p=p->next;
        }
        t=new node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}


int main(){
    int a[]={2, 5, 1, 6, 7};
    node* p=create(a, 5);
    display(p, p);
    insert(&p, 0, 4);
    cout<<endl;
    display(p, p);
}