#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

// iterative
node* search(node* p, int key){
    while(p){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return nullptr;
}

// recursive
node* rsearch(node* p, int key){
    if(!p){
        return nullptr;
    }
    if(key==p->data){
        return p;
    }
    return rsearch(p->next, key);
}

// improved search- move to head
node* isearch(node* p, int key){
    node *first=p;
    node *q=nullptr;
    while(p){
        if(key==p->data){
            return p;
            q->next=p->next;
            p->next=first;
            first=p;
        }
        q=p;
        p=p->next;
    }
    return nullptr;
}

int main(){
    int a[]={7, 3, 6, 4, 5, 2, 1};
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
    cout<<search(p, 6)<<endl;
    cout<<rsearch(p, 6)<<endl;
    cout<<isearch(p, 6)<<endl;
}