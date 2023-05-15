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

// reversing data
void revdata(node*& p, int x){
    int a[x];
    node* s=p;
    int i=0;
    while(s){
        a[i]=s->data;
        s=s->next;
        i++;
    }
    s=p;
    i--;
    while(s){
        s->data=a[i--];
        s=s->next;
    }
}

// reversing links
void revlink(node*& first){
    node *p=first;
    node* q=NULL;
    node* r=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    node* head=new node;
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
    revdata(p, sizeof(a)/sizeof(a[0]));
    cout<<endl<<"after reversing data : "<<endl;
    display(p);
    cout<<endl<<"after reversing links: "<<endl;
    revlink(p);
    display(p);
}