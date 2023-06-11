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
    node* head=new node;
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

void middle1(node* p){
    int n=0;
    node* q=p;
    while(p){
        n++;
        p=p->next;
    }
    int mid=n/2;
    if(n%2!=0){
        mid+=1;
    }
    for(int i=0; i<mid-1; i++){
        q=q->next;
    }
    cout<<"middle element by method 1 is: "<<q->data<<endl;
}

void middle2(node* p){
    node* q=p;
    while(q){
        q=q->next;
        if(q){
            q=q->next;
        }
        if(q){
            p=p->next;
        }
    }
    cout<<"middle element by method 2 is: "<<p->data<<endl;
}

void middle3(node* p){
    stack<node*> s;
    while(p){
        s.push(p);
        p=p->next;
    }
    int len=s.size();
    int poplen=(int)(floor(len/2));
    while(poplen){
        s.pop();
        poplen--;
    }
    cout<<"middle element by method 3 is: "<<s.top()->data<<endl;
}

int main(){
    int a[]={1, 2, 3, 4, 5, 6, 7};
    node* p=create(a, 7);
    middle1(p);
    middle2(p);
    middle3(p);
}