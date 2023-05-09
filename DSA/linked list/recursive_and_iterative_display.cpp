#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

// iterative display
void display(node *p){
    cout<<"iterative display: ";
    do{
        cout<<p->data<<" -> ";
        p=p->next;
    }while(p);
    cout<<endl;
}

// recursive display
void rdisplay(node *p){
    if(p){
        cout<<p->data<<" -> ";
        rdisplay(p->next);
    }
}

// backward recursive display
void brdisplay(node *p){
    if(p){
        brdisplay(p->next);
        cout<<p->data<<" -> ";
    }
}

int main(){
    int a[]={1, 2, 3, 4, 5};
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
    display(p);
    cout<<"recursive display: ";
    rdisplay(p);
    cout<<endl;
    cout<<"recursive backward display: ";
    brdisplay(p);
}