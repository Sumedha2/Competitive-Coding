#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int isoperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')'){
        return 0;
    }
    return 1;
}

int outpre(char x){
    if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 3;
    }
    else if(x=='^'){
        return 6;
    }
    else if(x=='('){
        return 7;
    }
    else if(x==')'){
        return 0;
    }
    return -1;
}

int inpre(char x){
    if(x=='+'||x=='-'){
        return 2;
    }
    else if(x=='*'||x=='/'){
        return 4;
    }
    else if(x=='^'){
        return 5;
    }
    else if(x=='('){
        return 0;
    }
    return -1;
}

char* convert(char* infix){
    char* postfix=new char[strlen(infix)+1];
    stack<char> st;
    int i=0, j=0;
    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(st.empty() || outpre(infix[i])>inpre(st.top())){
                st.push(infix[i++]);
            }
            else if(outpre(infix[i])==inpre(st.top())){
                st.pop();
            }
            else{
                postfix[j++]=st.top();
                st.pop();
            }
        }
    }
    while(!st.empty() && st.top()!=')'){
        postfix[j++]=st.top();
        st.pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char infix[]="((a+b)*c)-d^e^f";
    cout<<convert(infix)<<endl;
}