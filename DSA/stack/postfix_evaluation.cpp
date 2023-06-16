#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int isoperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return 0;
    }
    return 1;
}

int operation(char op, int x, int y){
    if(op=='+'){
        return x+y;
    }
    else if(op=='-'){
        return x-y;
    }
    else if(op=='*'){
        return x*y;
    }
    return x/y;
}

int eval(char* postfix){
    stack<int> st;
    int x, y, res;
    for(int i=0; postfix[i]!='\0'; i++){
        if(isoperand(postfix[i])){
            st.push(postfix[i]-'0');
        }
        else{
            y=st.top();
            st.pop();
            x=st.top();
            st.pop();
            res=operation(postfix[i], x, y);
            st.push(res);
        }
    }
    res=st.top();
    st.pop();
    return res;
}

int main(){
    char postfix[]="35*62/+4-";
    cout<<eval(postfix)<<endl;
}