class Solution {
public:

bool pal(int x){
    int temp=x, rev=0;
    while(temp>0){
        int d=temp%10;
        rev=rev*10 + d;
        temp/=10;
    }
    if(rev==x){
        return true;
    }
    return false;
}
int PalinArray(int a[], int n)
    {
    	for(int i=0; i<n; i++){
    	    if(!pal(a[i])){
    	        return 0;
    	    }
    	}
    	return 1;
    }
};