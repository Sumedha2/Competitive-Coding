#include <iostream>
#include <cstring>
#include <stack>
#include <map>
using namespace std;

int isbalanced(char* exp){
    map<char, char> mp;
    mp['}']='{';
    mp[']']='[';
    mp[')']='(';

    map<char, char>::iterator itr;
    stack<char> stk;
    
    for(int i=0; i<strlen(exp); i++){
        if(exp[i]=='{'||exp[i]=='['||exp[i]=='('){
            stk.push(exp[i]);
        }
        else if(exp[i]=='}'||exp[i]==']'||exp[i]==')'){
            if(stk.empty()){
                return false;
            }
            else{
                char temp=stk.top();
                itr=mp.find(exp[i]);
                if(temp==itr->second){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
    }
    return stk.empty()?true:false;
}

int main(){
    char a[]="{([a+b]*[c-d])/e}";
    char b[]="{([a+b]}*[c-d])/e}";
    char c[]="{([{a+b]*[c-d])/e}";
    cout<<isbalanced(a)<<endl<<isbalanced(b)<<endl<<isbalanced(c)<<endl;
}