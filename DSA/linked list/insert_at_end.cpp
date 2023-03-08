#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
void printlist(node* n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}
void add_end(node** head, int new_data){
    node* new_node=new node();
    node *last=*head;
    new_node->data=new_data;
    new_node->next=NULL;
    if(*head==NULL){
        *head=new_node;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
    return;
}

int main(){
    node* head=NULL;
    node* second=NULL;
    node* third=NULL;
    head=new node();
    second=new node();
    third=new node();
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    printlist(head);
    add_end(&head, 8);
    printlist(head);
    return 0;
}