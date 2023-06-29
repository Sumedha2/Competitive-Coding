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
    int count(node* p);
    int count(){return count(root);}
    int sum(node* p);
    int sum(){return sum(root);}
    int deg2count(node* p);
    int deg2count(){return deg2count(root);}
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

int tree::count(node* p){
    int x, y;
    if(p){
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int tree::sum(node* p){
    int x, y;
    if(p){
        x=sum(p->lchild);
        y=sum(p->rchild);
        return x+y+p->data;
    }
    return 0;
}

int tree::deg2count(node* p){
    int x, y;
    if(p){
        x=deg2count(p->lchild);
        y=deg2count(p->rchild);
        if(p->lchild&&p->rchild){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}
int main(){
    tree bt;
    int preorder[]={4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[]={7, 6, 9, 3, 4, 5, 8, 2, 1};

    int size=sizeof(inorder)/sizeof(inorder[0]);
    node* t=bt.generatetree(inorder, preorder, 0, size-1);

    cout<<"preorder: ";
    bt.preorder(t);
    cout<<endl;

    cout<<"inorder";
    bt.inorder(t);
    cout<<endl;

    cout<<"height: "<<bt.height(t)<<endl;
    cout<<"count: "<<bt.count(t)<<endl;
    cout<<"sum: "<<bt.sum(t)<<endl;
    cout<<"no. of 2 degree nodes: "<<bt.deg2count(t)<<endl;

    return 0;
}