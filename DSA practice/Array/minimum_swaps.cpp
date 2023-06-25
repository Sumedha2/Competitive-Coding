
class Solution
{
public:
    int minSwap(int a[], int n, int k) {
        int c=0, p=0, res=INT_MAX;
        for(int i=0; i<n; i++){
            if(a[i]<=k){
                c++;
            }
        }
        if(c==0){
            return 0;
        }
        int i=0, j=0;
        while(j<n){
            if(a[j]>k){
                p++;
            }
            if(j-i+1<c){
                j++;
            }
            else if(j-i+1==c){
                res=min(res, p);
                if(a[i]>k){
                    p--;
                }
                i++;
                j++;
            }
        }
        return res;
    }
};