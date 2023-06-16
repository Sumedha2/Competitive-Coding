#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int pre(char x){
    if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 2;
    }
    return 0;
}

int isoperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return 0;
    }
    return 1;
}

char* convert(const char* infix){
    int len=strlen(infix);
    char* postfix=new char[len+1];
    stack<char> st;
    int i=0, j=0;
    while(infix[i]!='\0'){
        cout<<infix[i];
        if(isoperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(st.empty()){
                st.push(infix[i++]);
            }
            else if(pre(infix[i])>pre(st.top())){
                st.push(infix[i++]);
            }
            else{
                if(!st.empty()){
                    postfix[j++]=st.top();
                    st.pop();
                }
            }
        }
    }
    cout<<endl;
    while(!st.empty()){
        postfix[j++]=st.top();
        st.pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    const char* infix="a+b*c-d/e";
    char* postfix=convert(infix);
    for(int i=0; i<strlen(postfix); i++){
        cout<<postfix[i];
    }
    cout<<endl;
}