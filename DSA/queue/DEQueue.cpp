#include <iostream>
using namespace std;

class DEQueue{
    private:
    int front;
    int rear;
    int size;
    int* q;
    public:
    DEQueue(int size);
    ~DEQueue();
    void display();
    void enqueuefront(int x);
    void enqueuerear(int x);
    int dequeuefront();
    int dequeuerear();
    bool isempty();
    bool isfull();
};

DEQueue::DEQueue(int size){
    this->size=size;
    front=-1;
    rear=-1;
    q=new int[size];
}

DEQueue::~DEQueue(){
    delete[] q;
}

bool DEQueue::isempty(){
    if(front==rear){
        return true;
    }
    return false;
}

bool DEQueue::isfull(){
    if(rear==size-1){
        return true;
    }
    return false;
}

void DEQueue::enqueuefront(int x){
    if(front==-1){
        cout<<"DEQueue overflow"<<endl;
    }
    else{
        q[front]=x;
        front--;
    }
}

void DEQueue::enqueuerear(int x){
    if(isfull()){
        cout<<"DEQueue overflow"<<endl;
    }
    else{
        rear++;
        q[rear]=x;
    }
}

int DEQueue::dequeuefront(){
    int x=-1;
    if(isempty()){
        cout<<"DEQueue underflow"<<endl;
    }
    else{
        x=q[front];
        front++;
    }
    return x;
}

int DEQueue::dequeuerear(){
    int x=-1;
    if(rear==-1){
        cout<<"DEQueue underflow"<<endl;
    }
    else{
        x=q[rear];
        rear--;
    }
    return x;
}

void DEQueue::display(){
    for(int i=front+1; i<=rear; i++){
        cout<<q[i];
        if(i<rear){
            cout<<"<-";
        }
    }
    cout<<endl;
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    DEQueue q(5);
    for(int i=0; i<5; i++){
        q.enqueuerear(a[i]);
    }
    q.display();
    q.dequeuefront();
    q.dequeuerear();
    q.enqueuefront(7);
    q.enqueuerear(8);
    q.display();
}