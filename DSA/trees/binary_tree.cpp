#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    node* lchild;
    int data;
    node* rchild;
};

class tree{
    private:
    node* root;
    public:
    tree();
    void createtree();
    void preorder(node* p);
    void preorder(){preorder(root);}
    void inorder(node* p);
    void inorder(){inorder(root);}
    void postorder(node* p);
    void postorder(){postorder(root);}
    void levelorder(node* p);
    void levelorder(){levelorder(root);}
    int height(node* p);
    int height(){return height(root);}
};

tree::tree(){
    root=nullptr;
}


void tree::createtree(){
    node* p;
    node* t;
    int x;
    queue<node*> q;
    root= new node;
    cout<<"enter root data: ";
    cin>>x;
    root->data=x;
    root->lchild=nullptr;
    root->rchild=nullptr;
    q.push(root);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<"enter left child of : "<<p->data<<" : ";
        cin>>x;
        if(x!=-1){
            t=new node;
            t->data=x;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->lchild=t;
            q.push(t);
        }
        cout<<"enter right child of : "<<p->data<<" : ";
        cin>>x;
        if(x!=-1){
            t=new node;
            t->data=x;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->rchild=t;
            q.push(t);
        }
    }
}
void tree::preorder(node* p){
    if(p){
        cout<<p->data<<", ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void tree::inorder(node* p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<", ";
        inorder(p->rchild);
    }
}

void tree::postorder(node* p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<", ";
    }
}

void tree:: levelorder(node* p){
    queue<node*> q;
    cout<<root->data<<", ";
    q.push(root);
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->lchild){
            cout<<p->lchild->data<<", ";
            q.push(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<", ";
            q.push(p->rchild);
        }
    }
}

int tree::height(node* p){
    int l=0, r=0;
    if(!p){
        return 0;
    }
    l=height(p->lchild);
    r=height(p->rchild);
    if(l>r){
        return l+1;
    }
    return r+1;
}

int main(){
    tree bt;
    bt.createtree();
    cout<<endl;

    cout<<"preorder: ";
    bt.preorder();
    cout<<endl;

    cout<<"inorder: ";
    bt.inorder();
    cout<<endl;

    cout<<"postorder: ";
    bt.postorder();
    cout<<endl;

    cout<<"levelorder: ";
    bt.levelorder();
    cout<<endl;

    cout<<"height: "<<bt.height()<<endl;

    return 0;
}