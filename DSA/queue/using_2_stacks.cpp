#include <iostream>
#include <stack>
using namespace std;

class queue{
    private:
    stack<int> e_st;
    stack<int> d_st;
    public:
    queue(){};
    ~queue(){};
    void enqueue(int x);
    int dequeue();
};

void queue::enqueue(int x){
    e_st.push(x);
}

int queue::dequeue(){
    int x=-1;
    if(d_st.empty()){
        if(e_st.empty()){
            cout<<"queue underflow"<<endl;
            return x;
        }
        else{
            while(!e_st.empty()){
                d_st.push(e_st.top());
                e_st.pop();
            }
        }
    }
    x=d_st.top();
    d_st.pop();
    return x;
}

int main(){
    int a[]={1, 2, 3, 4, 5};
    queue q;
    for(int i=0; i<5; i++){
        q.enqueue(a[i]);
        cout<<a[i];
        if(i<4){
            cout<<"<-";
        }
    }
    cout<<endl;
    for(int i=0; i<5; i++){
        cout<<q.dequeue();
        if(i<4){
            cout<<"<-";
        }
    }
    return 0;

}