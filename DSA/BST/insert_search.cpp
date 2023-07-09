#include <iostream>
using namespace std;

class node{
    public:
    node* lchild;
    int data;
    node* rchild;
};


class bst{
    private:
    node* root;
    public:
    bst(){root=nullptr;}
    node* getroot(){return root;}
    void insert(int key);
    void inorder(node* p);
    node* search(int key);
};

void bst::insert(int key){
    node* t=root;
    node* p;
    node* r;
    if(!root){
        p=new node;
        p->data=key;
        p->lchild=nullptr;
        p->rchild=nullptr;
        root=p;
        return ;
    }
    while(t){
        r=t;
        if(key<t->data){
            t=t->lchild;
        }
        else if(key>t->data){
            t=t->rchild;
        }
        else{
            return;
        }
    }
    p=new node;
    p->data=key;
    p->lchild=nullptr;
    p->rchild=nullptr;
    if(key<r->data){
        r->lchild=p;
    }
    else{
        r->rchild=p;
    }
}

void bst::inorder(node* p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<", ";
        inorder(p->rchild);
    }
}

node* bst::search(int key){
    node* t=root;
    while(t){
        if(key==t->data){
            return t;
        }
        else if(key<t->data){
            t=t->lchild;
        }
        else{
            t=t->rchild;
        }
    }
    return nullptr;
}

int main(){
    bst tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(7);
    tree.insert(25);
    tree.inorder(tree.getroot());
    cout<<endl;
    node* temp=tree.search(3);
    if(temp){
        cout<<temp->data<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
    return 0;
}