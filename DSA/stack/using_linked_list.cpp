#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

class stack{
    private:
    node* top;
    public:
    stack();
    ~stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isempty();
    int isfull();
    int stacktop();
};

stack::stack(){
    top=nullptr;
}

stack::~stack(){
    node* p=top;
    while(top){
        top=top->next;
        delete p;
        p=top;
    }
}

void stack::push(int x){
    node* t=new node;
    if(t==nullptr){
        cout<<"stack overflow"<<endl;
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int stack::pop(){
    node* p;
    int x=-1;
    if(top==nullptr){
        cout<<"stack underflow"<<endl;
    }
    else{
        p=top;
        x=p->data;
        top=top->next;
        delete p;
    }
    return x;
}

int stack::isfull(){
    node* t=new node;
    int r= t ? 1 : 0;
    delete t;
    return r;
}

int stack::isempty(){
    return top ? 0 : 1;
}

int stack::stacktop(){
    if(top){
        return top->data;
    }
    return -1;
}

int stack::peek(int index){
    if(isempty()){
        return -1;
    }
    else{
        node* p=top;
        for(int i=0; p!=nullptr && i<index-1; i++){
            p=p->next;
        }
        if(p!=nullptr){
            return p->data;
        }
        else{
            return -1;
        }
    }
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    stack stk;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
        stk.push(a[i]);
    }
    cout<<"peek at 0th: "<<stk.peek(0)<<endl;
    cout<<"peek at 3rd: "<<stk.peek(3)<<endl; 
    cout<<"peek at 6th: "<<stk.peek(6)<<endl;
    cout<<"stack top: "<<stk.stacktop()<<endl;
    cout<<"is stack full?: "<<stk.isfull()<<endl;
    cout<<"is stack empty?: "<<stk.isempty()<<endl;
    cout<<"popped elements: ";
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
        cout<<stk.pop()<<", ";
    }
    cout<<endl;
    cout<<stk.pop()<<endl;
}