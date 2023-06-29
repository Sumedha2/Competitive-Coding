#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
    public:
    node* lchild;
    int data;
    node* rchild;
    node() {};
    node(int data);
};

node::node(int data) {
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}

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
    void iterativepreorder(node* p);
    void iterativepreorder(){iterativepreorder(root);}
    void iterativeinorder(node* p);
    void iterativeinorder(){iterativeinorder(root);}
    void iterativepostorder(node* p);
    void iterativepostorder(){iterativepostorder(root);}
    node* generatetree(int* inorder, int* preorder, int start, int end);
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

void tree::iterativepreorder(node* p){
    stack<node*> stk;
    while(p || !stk.empty()){
        if(p){
            cout<<p->data<<", ";
            stk.push(p);
            p=p->lchild;
        }
        else{
            p=stk.top();
            stk.pop();
            p=p->rchild;
        }
    }
    cout<<endl;
}

void tree::iterativeinorder(node* p){
    stack<node*> stk;
    while(p || !stk.empty()){
        if(p){
            stk.push(p);
            p=p->lchild;
        }
        else{
            p=stk.top();
            stk.pop();
            cout<<p->data<<", ";
            p=p->rchild;
        }
    }
    cout<<endl;
}

void tree::iterativepostorder(node* p){
    stack<long int> stk;
    long int temp;
    while(p || !stk.empty()){
        if(p){
            stk.push((long int)p);
            p=p->lchild;
        }
        else{
            temp=stk.top();
            stk.pop();
            if(temp>0){
                stk.push(-temp);
                p=((node*)temp)->rchild;
            }
            else{
                cout<<((node*)(-1*temp))->data<<", ";
                p=nullptr;
            }
        }
    }
    cout<<endl;
}

int searchinorder(int inarray[], int start, int end, int data){
    for(int i=start; i<=end; i++){
        if(inarray[i]==data){
            return i;
        }
    }
    return -1;
}

node* tree::generatetree(int *inorder, int *preorder, int start, int end){
    static int pre=0;
    if(start>end){
        return nullptr;
    }
    node* n=new node(preorder[pre++]);
    if(start==end){
        return n;
    }
    int split=searchinorder(inorder, start, end, n->data);
    n->lchild=generatetree(inorder, preorder, start, split-1);
    n->rchild=generatetree(inorder, preorder, split+1, end);
    return n;
}

int main(){
    tree bt;
    int preorder[]={4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[]={7, 6, 9, 3, 4, 5, 8, 2, 1};

    node* t=bt.generatetree(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);
    bt.preorder(t);
    return 0;
}