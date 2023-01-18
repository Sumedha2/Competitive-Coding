#include <iostream>
using namespace std;

int main(){
    char A[]="How are   you?";
    int i, vcount=0, ccount=0, word=1;
    for(i=0; A[i]!='\0'; i++){
        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'||A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U'){
            vcount++;
        }
        else if((A[i]>=65 && A[i]<=90)||(A[i]>=97&&A[i]<=122)){
            ccount++;
        }
        else if(A[i]==' '&&A[i-1]!=' '){
            word++;
        }
    }
    printf("The vowel count is: %d\nThe consonant count is: %d\nThe word count is: %d",vcount, ccount, word);
}