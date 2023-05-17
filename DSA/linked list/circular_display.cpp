#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
node* head=new node;

node* create(int* a, int size){
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

// iterative display
void display(node* p){
    do{
        cout<<p->data<<" -> ";
        p=p->next;
    }while(p!=head);
}

// recursive display
void rdisplay(node* p){
    static int flag=0;
    if(p!=head||flag==0){
        flag=1;
        cout<<p->data<<" -> ";
        rdisplay(p->next);
    }
    flag=0;
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    node* p=create(a, 5);
    cout<<"iterative display: "<<endl;
    display(p);
    cout<<endl<<"recursive display: "<<endl;
    rdisplay(p);
}