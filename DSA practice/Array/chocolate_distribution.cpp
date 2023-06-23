class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long int l=0, r=m-1, res=INT_MAX;
        while(r<n){
            res=min(res, a[r++]-a[l++]);
        }
        return res;
    }   
};