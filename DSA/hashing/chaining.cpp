#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

class hash_table{
    public:
    node** ht;
    hash_table();
    int hash(int key);
    void insert(int key);
    int search(int key);
    ~hash_table();
};

hash_table::hash_table(){
    ht=new node* [10];
    for(int i=0; i<10; i++){
        ht[i]=nullptr;
    }
}

int hash_table::hash(int key){
    return key%10;
}

void hash_table::insert(int key){
    int idx=hash(key);
    node* t=new node;
    t->data=key;
    t->next=nullptr;
    if(ht[idx]==nullptr){
        ht[idx]=t;
    }
    else{
        node* p=ht[idx];
        node* q=ht[idx];
        while(p&&p->data<key){
            q=p;
            p=p->next;
        }
        if(q==ht[idx]){
            t->next=ht[idx];
            ht[idx]=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

int hash_table::search(int key){
    int idx=hash(key);
    node* p=ht[idx];
    while(p){
        if(p->data==key){
            return p->data;
        }
        p=p->next;
    }
    return -1;
}

hash_table::~hash_table(){
    for(int i=0; i<10; i++){
        node* p=ht[i];
        while(ht[i]){
            ht[i]=ht[i]->next;
            delete p;
            p=ht[i];
        }
    }
    delete [] ht;
}

int main(){
    int a[100], n;
    hash_table h;
    cout<<"enter size of array: ";
    cin>>n;
    cout<<"enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
        h.insert(a[i]);
    }
    cout<<"enter key to search: ";
    int k;
    cin>>k;
    int val=h.search(k);
    cout<<"key: "<<k<<", value: "<<val<<endl;
}