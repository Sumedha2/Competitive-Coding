// approach 1
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int a[], int n, int X)
    {
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if(a[i]+a[j]+a[k]==X){
                        return true;
                        break;
                    }
                }
            }
        }
        return false;
    }

};

// approach 2
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int a[], int n, int X)
    {
        sort(a, a+n);
        for(int i=0; i<n; i++){
            int l=i+1, r=n-1;
            while(l<r){
                if(a[i]+a[l]+a[r]==X){
                    return true;
                }
                else if(a[i]+a[l]+a[r]<X){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return false;
    }

};