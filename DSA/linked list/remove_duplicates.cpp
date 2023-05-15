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
// removing duplicates from sorted ll
void dup(node*& p){
    node* s=p;
    node* r=p->next;
    while(r){
        if(s->data!=r->data){
            s=r;
            r=r->next;
        }
        else{
            s->next=r->next;
            delete r;
            r=s->next;
        }
    }
}

int main(){
    int a[]={1, 2, 2, 4, 4, 5};
    node* head= new node;
    node* temp;
    node* last;
    head->data=a[0];
    head->next=nullptr;
    last=head;
    for(int i=1; i<sizeof(a)/sizeof(a[0]); i++){
        temp =new node;
        temp->data=a[i];
        temp->next=nullptr;
        last->next=temp;
        last=temp;
    }
    node* p=head;
    cout<<"before removal: "<<endl;
    display(p);
    dup(p);
    cout<<"after duplicate removal: "<<endl;
    display(p);
}