class Solution {
  public:
    int max(int a, int b){
        if(a>b){
            return a;
        }
        return b;
    }
    int min(int a, int b){
        if(a<b){
            return a;
        }
        return b;
    }
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);
        int maxi=0, mini=0, ans=arr[n-1]-arr[0], big=arr[n-1]-k, small=arr[0]+k;
        for(int i=0; i<n; i++){
            mini=min(small, arr[i+1]-k);
            maxi=max(big, arr[i]+k);
            if(mini<0){
                continue;
            }
            ans=min(ans, maxi-mini);
        }
        return ans;
    }
};