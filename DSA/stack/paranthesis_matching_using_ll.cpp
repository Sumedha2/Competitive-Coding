#include <iostream>
#include <cstring>
using namespace std;

class node{
    public:
    char data;
    node* next;
};

class stack{
    private:
    node* top;
    public:
    stack();
    ~stack();
    void push(char x);
    char pop();
    char peek(int index);
    int isempty();
    int isfull();
    char stacktop();
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
void stack::push(char x){
    node* t=new node;
    if(!t){
        cout<<"stack overflow";
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
char stack::pop(){
    node* p;
    char x=-1;
    if(!top){
        cout<<"stack underflow";
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
    int r=t?1:0;
    delete t;
    return r;
}
int stack::isempty(){
    return top?0:1;
}
char stack::stacktop(){
    if(top){
        return top->data;
    }
    return -1;
}
char stack::peek(int index){
    if(isempty()){
        return -1;
    }
    else{
        node* p=top;
        for(int i=0; p&&i<index-1; i++){
            p=p->next;
        }
        if(p){
            return p->data;
        }
        else{
            return -1;
        }
    }
}
int isbalanced(char* exp){
    stack stk;
    for(int i=0; i<strlen(exp); i++){
        if(exp[i]=='('){
            stk.push(exp[i]);
        }
        else if(exp[i]==')'){
            if(stk.isempty()){
                return false;
            }
            else{
                stk.pop();
            }
        }
    }
    return stk.isempty()?true:false;
}
int main(){
    char a[]="((a+b)*(c-d))";
    cout<<isbalanced(a)<<endl;

    char b[]="((a+b)*(c-d)))";
    cout<<isbalanced(b)<<endl;
}