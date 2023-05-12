#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

int max(node *p){
    int m=INT_MIN;
    while(p){
        if(p->data>m){
            m=p->data;
        }
        p=p->next;
    }
    return m;
}

int rmax(node *p){
    int m=0;
    if(!p){
        return INT_MIN;
    }
    else{
        m=max(p->next);
        if(m>p->data){
            return m;
        }
        else{
            return p->data;
        }
    }
}

int main(){
    int a[]={1, 2, 3, 4, 5, 6, 7, 8};
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
    cout<<"Maximum: "<<max(p)<<endl;
    cout<<"Maximum by recursive: "<<rmax(p);
}