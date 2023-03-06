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
void insert_after(node* prev, int new_data){
    node* new_node= new node();
    new_node->data=new_data;
    new_node->next=prev->next;
    prev->next=new_node;
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
    insert_after(second, 8);
    printlist(head);
    return 0;
}