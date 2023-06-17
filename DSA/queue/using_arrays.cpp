#include <iostream>
using namespace std;

class queue{
    private:
    int size;
    int front;
    int rear;
    int* q;
    public:
    queue(int size);
    ~queue();
    bool isempty();
    bool isfull();
    void enqueue(int x);
    int dequeue();
    void display();
};

queue::queue(int size){
    this->size=size;
    front=-1;
    rear=-1;
    q=new int[size];
}

queue::~queue(){
    delete [] q;
}

bool queue::isempty(){
    if(front==rear){
        return true;
    }
    return false;
}

bool queue::isfull(){
    if(rear==size-1){
        return true;
    }
    return false;
}

void queue::enqueue(int x){
    if(isfull()){
        cout<<"queue overflow"<<endl;
    }
    else{
        rear++;
        q[rear]=x;
    }
}

int queue::dequeue(){
    int x=-1;
    if(isempty()){
        cout<<"queue underflow"<<endl;
    }
    else{
        front++;
        x=q[front];
    }
    return x;
}

void queue::display(){
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
    queue q(5);

    for(int i=0; i<5; i++){
        q.enqueue(a[i]);
    }

    q.display();
    q.dequeue();
    q.display(); 
}