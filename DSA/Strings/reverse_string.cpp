#include <iostream>
using namespace std;

int main(){
    char A[]="python";
    char B[7];
    int i, j;
    for(i=0; A[i]!='\0'; i++){}
    for((j=0 && i>=0); i--; j++){
        B[j]=A[i];
    }
    B[j]='\0';
    printf("by reverse copying string: %s \n", B);

    char C[]="python";
    char t;
    int k, l;
    for(l=0; C[l]!='\0'; l++){}
    l=l-1;
    for(k=0; k<l; k++){
        t=C[k];
        C[k]=C[l];
        C[l]=t;
        l--;
    }
    printf("by swaping: %s", C);
}