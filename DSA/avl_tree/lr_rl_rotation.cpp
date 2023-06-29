#include <iostream>
using namespace std;

class node{
    public:
    node* lchild;
    int data;
    node* rchild;
    int height;
};

class avl{
    public:
    node* root;
    avl(){root=nullptr;}
    int nodeheight(node* p);
    int balancefactor(node* p);
    node* ll(node* p);
    node* rr(node* p);
    node* lr(node* p);
    node* rl(node* p);
    node* rinsert(node* p, int key);
    void inorder(node* p);
    void inorder(){inorder(root);}
    node* getroot(){return root;}
};

int avl::nodeheight(node* p){
    int hl, hr;
    hl=(p&&p->lchild)?p->lchild->height:0;
    hr=(p&&p->rchild)?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}

int avl::balancefactor(node* p){
    int hl, hr;
    hl=(p&&p->lchild)?p->lchild->height:0;
    hr=(p&&p->rchild)?p->rchild->height:0;
    return hl-hr;
}

node* avl::ll(node* p){
    node* pl=p->lchild;
    node* plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=nodeheight(p);
    pl->height=nodeheight(pl);
    if(root==p){
        root=pl;
    }
    return pl;
}

node* avl::rr(node* p){
    node* pr=p->rchild;
    node* prl=pr->lchild;
    pr->lchild=p;
    p->rchild=prl;
    p->height=nodeheight(p);
    pr->height=nodeheight(pr);
    if(root==p){
        root=pr;
    }
    return pr;
}

node* avl::lr(node* p){
    node* pl=p->lchild;
    node* plr=pl->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    pl->height=nodeheight(pl);
    p->height=nodeheight(p);
    plr->height=nodeheight(plr);

    if(p==root){
        root=plr;
    }
    return plr;
}

node* avl::rl(node* p){
    node* pr=p->rchild;
    node* prl=pr->lchild;
    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;
    prl->rchild=pr;
    prl->lchild=p;
    pr->height=nodeheight(pr);
    p->height=nodeheight(p);
    prl->height=nodeheight(prl);

    if(p==root){
        root=prl;
    }
    return prl;
}

node* avl::rinsert(node* p, int key){
    node* t;
    if(!p){
        t=new node;
        t->data=key;
        t->lchild=nullptr;
        t->rchild=nullptr;
        t->height=1;
        return t;
    }
    if(key<p->data){
        p->lchild=rinsert(p->lchild, key);
    }
    else if(key>p->data){
        p->rchild=rinsert(p->rchild, key);
    }
    p->height=nodeheight(p);
    if(balancefactor(p)==2 && balancefactor(p->lchild)==1){
        return ll(p);
    }
    else if(balancefactor(p)==2 && balancefactor(p->lchild)==-1){
        return lr(p);
    }
    else if(balancefactor(p)==-2 && balancefactor(p->lchild)==-1){
        return rr(p);
    }
    else if(balancefactor(p)==-2 && balancefactor(p->lchild)==1){
        return rl(p);
    }
    return p;
}

void avl::inorder(node* p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<", ";
        inorder(p->rchild);
    }
}

int main(){
    avl tree;
    tree.root=tree.rinsert(tree.root, 50);
    tree.root=tree.rinsert(tree.root, 10);
    tree.root=tree.rinsert(tree.root, 20);

    tree.inorder();
    cout<<endl;

    avl tree2;
    tree2.root=tree2.rinsert(tree2.root, 20);
    tree2.root=tree2.rinsert(tree2.root, 50);
    tree2.root=tree2.rinsert(tree2.root, 30);

    tree2.inorder();
    cout<<endl;

    return 0;
}