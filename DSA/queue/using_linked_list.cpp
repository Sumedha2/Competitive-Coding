#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

class queue{
    private:
    node* front;
    node* rear;
    public:
    queue();
    ~queue();
    void enqueue(int x);
    int dequeue();
    bool isempty();
    void display();
};

queue::queue(){
    front=nullptr;
    rear=nullptr;
}

queue::~queue(){
    node* p= front;
    while(front){
        front=front->next;
        delete p;
        p=front;
    }
}

void queue::enqueue(int x){
    node* t=new node;
    if(!t){
        cout<<"queue overflow"<<endl;
    }
    else{
        t->data=x;
        t->next=nullptr;
        if(!front){
            front=t;
            rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int queue::dequeue(){
    int x=-1;
    node* p;
    if(isempty()){
        cout<<"queue underflow"<<endl;
    }
    else{
        p=front;
        front=front->next;
        x=p->data;
        delete p;
    }
    return x;
}

bool queue::isempty(){
    if(!front){
        return true;
    }
    return false;
}

void queue::display(){
    node* p=front;
    while(p){
        cout<<p->data;
        p=p->next;
        if(p){
            cout<<"<-";
        }
    }
    cout<<endl;
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    queue q;
    for(int i=0; i<5; i++){
        q.enqueue(a[i]);
    }
    q.display();
    q.dequeue();
    q.enqueue(7);
    q.display();
}