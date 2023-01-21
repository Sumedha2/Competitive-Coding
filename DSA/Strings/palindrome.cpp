#include <iostream>
using namespace std;

int main(){
    char A[]="madam";
    char B[6];
    int i, j;
    for(i=0; A[i]!='\0'; i++){}
    for((j=0&& i>=0); i--; j++){
        B[j]=A[i];
    }
    B[j]='\0';
    int k, l=0;
    for(k=0; A[k]!='\0'&&B[k]!='\0'; k++){
        if (A[k]!=B[l]){
            break;
        }
        l++;
    }
    if(A[k]==B[j]){
        printf("palindrome");
    }
    else{
        printf("not palindrome");
    }
}