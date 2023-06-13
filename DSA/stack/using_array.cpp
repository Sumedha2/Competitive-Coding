#include <iostream>
using namespace std;

class stack{
    private:
    int size;
    int top;
    int* s;
    public:
    stack(int size);
    ~stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isfull();
    int isempty();
    void display();
    int stacktop();
};

stack::stack(int size){
    this->size=size;
    top=-1;
    s=new int[size];
}

stack::~stack(){
    delete[] s;
}

void stack::push(int x){
    if(isfull()){
        cout<<"stack overflow"<<endl;
    }
    else{
        top++;
        s[top]=x;
    }
}

int stack::pop(){
    int x=-1;
    if(isempty()){
        cout<<"stack underflow"<<endl;
    }
    else{
        x=s[top];
        top--;
    }
    return x;
}

int stack::peek(int index){
    int x=-1;
    if(top-index+1<0||top-index+1==size){
        cout<<"invalid position"<<endl;
    }
    else{
        x=s[top-index+1];
    }
    return x;
}

int stack::isfull(){
    if(top==size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int stack::isempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void stack::display(){
    for(int i=top; i>=0; i--){
        cout<<s[i]<<" | ";
    }
    cout<<endl;
}

int stack::stacktop(){
    if(isempty()){
        return -1;
    }
    return s[top];
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    stack stk(sizeof(a)/sizeof(a[0]));
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
        stk.push(a[i]);
    }
    stk.push(6);
    cout<<"is stack full ?: "<<stk.isfull()<<endl;
    cout<<"stack: ";
    stk.display();
    cout<<"peek at 0: "<<stk.peek(0)<<endl;
    cout<<"peek at 2: "<<stk.peek(2)<<endl;
    cout<<"peek at 6: "<<stk.peek(6)<<endl;
    cout<<"top element: "<<stk.stacktop()<<endl;
    cout<<"popped out elements: ";
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
        cout<<stk.pop()<<", ";
    }
    cout<<endl;
    stk.pop();
    cout<<"is stack empty?: "<<stk.isempty()<<endl;
}
