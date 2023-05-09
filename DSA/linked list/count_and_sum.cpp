#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

// iterative count
int count(node *p){
    int c=0;
    while(p){
        c+=1;
        p=p->next;
    }
    return c;
}

// recursive count
int rcount(node *p){
    if(!p){
        return 0;
    }
    return rcount(p->next)+1;
}

// iterative sum
int sum(node *p){
    int s=0;
    while(p){
        s=s+p->data;
        p=p->next;
    }
    return s;
}

// recursive sum
int rsum(node *p){
    int s=0;
    if(!p){
        return 0;
    }
    return rsum(p->next)+p->data;
}

int main(){
    int a[]={1, 2, 3, 4, 5, 6, 7};
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
    cout<<"count: "<<count(p)<<endl;
    cout<<"recursive count: "<<rcount(p)<<endl;
    cout<<"sum: "<<sum(p)<<endl;
    cout<<"recursive sum: "<<rsum(p);
}