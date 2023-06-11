#include <iostream>
#include <cmath>
#include <stack>
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
        temp= new node;
        temp->data=a[i];
        temp->next=nullptr;
        last->next=temp;
        last=temp;
    }
    return head;
}

void intersection(node* p, node* q){
    stack<node*> stk1;
    while(p){
        stk1.push(p);
        p=p->next;
    }

    stack<node*> stk2;
    while(q){
        stk2.push(q);
        q=q->next;
    }

    node* r;
    while(stk1.top()==stk2.top()){
        r=stk1.top();
        stk1.pop();
        stk2.pop();
    }
    cout<<"intersecting node: "<<r->data<<endl;
}

int main(){
    int a[]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    node* head=create(a, 11);
    node* temp=head;
    int i=5;
    while(i>0){
        temp=temp->next;
        i--;
    }
    cout<<temp->data<<endl;
    int b[]={2, 4, 6, 8, 10};
    node* second=create(b, 5);
    intersection(head, second);
}