#include <iostream>
#include <cmath>
using namespace std;

class node{
    public:
    int coeff;
    int exp;
    node* next;
};

node* create(){
    node* poly=nullptr;
    node* t;
    node* last=nullptr;
    int num, i;
    cout<<"enter number of terms: ";
    cin>>num;
    cout<<"enter each term with coefficient and exponent: ";
    for(int i=0; i<num; i++){
        t=new node;
        cin>>t->coeff>>t->exp;
        t->next=nullptr;
        if(!poly){
            poly=last=t;
        }
        else{
            last->next=t;
            last=t;
        }
    }
    return poly;
}

void display(node* p){
    while(p){
        cout<<p->coeff<<"x^"<<p->exp<<" + ";
        p=p->next;
    }
    cout<<endl;
}

long eval(node* p, int x){
    long val=0;
    while(p){
        val+=p->coeff*pow(x, p->exp);
        p=p->next;
    }
    return val;
}

int main(){
    node* poly=create();
    display(poly);
    cout<<eval(poly, 1);
}