#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
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
    while(p){
        cout<<p->data<<" -> ";
        p=p->next;
    }
    return 0;
}