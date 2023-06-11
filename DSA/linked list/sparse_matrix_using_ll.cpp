#include <iostream>
using namespace std;

class node{
    public:
    int row;
    int col;
    int data;
    node* next;
};

void create(node*& p, int ri, int ci, int val){
    node* temp=p;
    node* r;
    if(temp==nullptr){
        temp= new node;
        temp->row=ri;
        temp->col=ci;
        temp->data=val;
        temp->next=nullptr;
        p=temp;
    }
    else{
        while(temp->next){
            temp=temp->next;
        }
        r=new node;
        r->row=ri;
        r->col=ci;
        r->data=val;
        r->next=nullptr;
        temp->next=r;
    }
}

void display(node* p){
    node* s=p;
    cout<<"row: ";
    while(s){
        cout<<s->row<<" ";
        s=s->next;
    }
    cout<<endl;
    cout<<"column: ";
    s=p;
    while(s){
        cout<<s->col<<" ";
        s=s->next;
    }
    cout<<endl;
    cout<<"value: ";
    s=p;
    while(s){
        cout<<s->data<<" ";
        s=s->next;
    }
}

int main(){
    int mat[5][6]={{0, 1, 0, 0, 2, 0}, {0, 0, 9, 8, 0, 0}, {1, 0, 7, 0, 0, 0}, {0, 0, 0, 0, 0, 2}, {0, 5, 2, 0, 0, 0}};
    node* head=nullptr;
    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            if(mat[i][j]!=0){
                create(head, i, j, mat[i][j]);
            }
        }
    }
    display(head);
}