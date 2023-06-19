#include <iostream>
using namespace std;

class circularqueue{
    private:
    int size;
    int front;
    int rear;
    int* q;
    public:
    circularqueue(int size);
    ~circularqueue();
    bool isfull();
    bool isempty();
    void enqueue(int x);
    int dequeue();
    void display();
};

circularqueue::circularqueue(int size){
    this->size=size;
    front=0;
    rear=0;
    q=new int[size];
}

circularqueue::~circularqueue(){
    delete [] q;
}

bool circularqueue::isempty(){
    if(front==rear){
        return true;
    }
    return false;
}

bool circularqueue::isfull(){
    if((rear+1)%size==front){
        return true;
    }
    return false;
}

void circularqueue::enqueue(int x){
    if(isfull()){
        cout<<"queue overflow"<<endl;
    }
    else{
        rear=(rear+1)%size;
        q[rear]=x;
    }
}

int circularqueue::dequeue(){
    int x=-1;
    if(isempty()){
        cout<<"queue underflow"<<endl;
    }
    else{
        front=(front+1)%size;
        x=q[front];
    }
    return x;
}

void circularqueue::display(){
    int i=front+1;
    do{
        cout<<q[i];
        if(i<rear){
            cout<<"<-";
        }
        i=(i+1)%size;
    } while(i!=(rear+1)%size);
    cout<<endl;
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    circularqueue q(6);
    for(int i=0; i<5; i++){
        q.enqueue(a[i]);
    }
    q.display();
    q.dequeue();
    q.enqueue(7);
    q.display();
}
