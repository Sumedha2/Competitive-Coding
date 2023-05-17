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
        temp=new node;
        temp->data=a[i];
        temp->next=nullptr;
        last->next=temp;
        last=temp;
    }
    return head;
}

void display(node* p){
    while(p){
        cout<<p->data<<" -> ";
        p=p->next;
    }
}

int main(){
    int a[]={1, 3, 5, 7};
    int b[]={2, 4, 6, 8};
    node* first=create(a, 4);
    node* second=create(b, 4);

    // merge two linked lists
    node* third=nullptr;
    node* last;
    if(first->data<second->data){
        third=last=first;
        first=first->next;
        third->next=nullptr;
    }
    else{
        third=last=second;
        second=second->next;
        third->next=nullptr;
    }
    while(first&&second){
        if(first->data<second->data){
            last->next=first;
            last=first;
            first=first->next;
            last->next=nullptr;
        }
        else{
            last->next=second;
            last=second;
            second=second->next;
            last->next=nullptr;
        }
        if(first){
            last->next=first;
        }
        if(second){
            last->next=second;
        }
    }
    display(third);
}
//     cout<<endl;
//     display(second);
