#include <iostream>
using namespace std;

int main(){
    char A[]="painter";
    char B[]="painting";
    int i, j=0;
    for(i=0; A[i]!='\0'&&B[j]!='\0'; i++){
        if (A[i]!=B[j]){
            break;
        }
        j++;
    }
    if(A[i]==B[j]){
        printf("equal");
    }
    else if(A[i]<B[j]){
        printf("smaller");
    }
    else{
        printf("greater");
    }
}