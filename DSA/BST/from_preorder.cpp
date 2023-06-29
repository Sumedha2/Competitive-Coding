#include <iostream>
#include <stack>
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
    node* rinsert(node* p, int key);
    node* rsearch(node* p, int key);
    node* ddelete(node* p, int key);
    int height(node* p);
    node* inpre(node* p);
    node* insucc(node* p);
    void createfrompreorder(int pre[], int n);
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
        return;
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

node* bst::rinsert(node* p, int key){
    node* t;
    if(!p){
        t=new node;
        t->data=key;
        t->lchild=nullptr;
        t->rchild=nullptr;
        return t;
    }
    if(key<p->data){
        p->lchild=rinsert(p->lchild, key);
    }
    else if(key>p->data){
        p->rchild=rinsert(p->rchild, key);
    }
    return p;
}

node* bst::rsearch(node* p, int key){
    if(!p){
        return nullptr;
    }
    if(key==p->data){
        return p;
    }
    else if(key<p->data){
        return rsearch(p->lchild, key);
    }
    else{
        return rsearch(p->rchild, key);
    }
}

node* bst::ddelete(node* p, int key){
    node* q;
    if(!p){
        return nullptr;
    }
    if(!p->lchild && !p->rchild){
        if(p==root){
            root=nullptr;
        }
        delete p;
        return nullptr;
    }
    if(key<p->data){
        p->lchild=ddelete(p->lchild, key);
    }
    else if(key>p->data){
        p->rchild=ddelete(p->rchild, key);
    }
    else{
        if(height(p->lchild)>height(p->rchild)){
            q=inpre(p->lchild);
            p->data=q->data;
            p->lchild=ddelete(p->lchild, q->data);
        }
        else{
            q=insucc(p->rchild);
            p->data=q->data;
            p->rchild=ddelete(p->rchild, q->data);
        }
    }
    return p;
}

int bst::height(node* p){
    int x, y;
    if(!p){
        return 0;
    }
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}

node* bst::inpre(node* p){
    while(p&&p->rchild){
        p=p->rchild;
    }
    return p;
}

node* bst::insucc(node* p){
    while(p&&p->lchild){
        p=p->lchild;
    }
    return p;
}

void bst::createfrompreorder(int* pre, int n){
    int i=0;
    root=new node;
    root->data=pre[i++];
    root->lchild=nullptr;
    root->rchild=nullptr;

    node* t;
    node* p=root;
    stack<node*> stk;
    while(i<n){
        if(pre[i]<p->data){
            t=new node;
            t->data=pre[i++];
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->lchild=t;
            stk.push(p);
            p=t;
        }
        else{
            if(pre[i]>p->data&&pre[i]<stk.empty()?32767:stk.top()->data){
                t=new node;
                t->data=pre[i++];
                t->lchild=nullptr;
                t->rchild=nullptr;
                p->rchild=t;
                p=t;
            }
            else{
                p=stk.top();
                stk.pop();
            }
        }
    }
}

int main(){
    bst tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(8);
    tree.insert(30);
    tree.inorder(tree.getroot());
    cout<<endl;
    node* temp=tree.search(2);
    if(temp){
        cout<<temp->data<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }

    tree.rinsert(tree.getroot(), 50);
    tree.rinsert(tree.getroot(), 70);
    tree.rinsert(tree.getroot(), 1);
    tree.inorder(tree.getroot());
    cout<<endl;

    bst tree2;
    tree2.insert(5);
    tree2.insert(2);
    tree2.insert(8);
    tree2.insert(7);
    tree2.insert(9);
    tree2.insert(1);

    temp=tree2.inpre(tree2.getroot());
    cout<<"inorder predecessor: "<<temp->data<<endl;

    temp=tree2.insucc(tree2.getroot());
    cout<<"inorder successor: "<<temp->data<<endl;

    tree2.inorder(tree2.getroot());
    cout<<endl;

    tree2.ddelete(tree2.getroot(), 7);
    tree2.inorder(tree2.getroot());
    cout<<endl;

    cout<<"BST from preorder traversal: ";
    int pre[]={30, 20, 10, 15, 25, 40, 50, 45};
    int m=sizeof(pre)/sizeof(pre[0]);
    cout<<endl;
    
    bst tree3;
    tree3.createfrompreorder(pre, m);
    tree3.inorder(tree3.getroot());
    cout<<endl;

    return 0; 

}