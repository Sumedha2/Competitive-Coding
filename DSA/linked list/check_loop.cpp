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
        temp= new node;
        temp->data=a[i];
        temp->next=nullptr;
        last->next=temp;
        last=temp;
    }
    return head;
}

// check for loop
bool isloop(node* first){
    node* p;
    node* q;
    p=q=first;
    if(!p||!p->next){
        return false;
    }
    do{
        p=p->next;
        q=q->next;
        q=q!=nullptr?q->next:nullptr;
    }while((p&&q)&&(p!=q));
    return p==q?true:false;
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    node* first=create(a, 5);
    node* t1;
    node* t2;
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;

    cout<<isloop(first)<<endl;
    
}