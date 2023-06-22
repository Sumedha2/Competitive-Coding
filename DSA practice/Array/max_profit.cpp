class Solution {
  public:
    int maxProfit(int k, int n, int arr[]) {
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        for(int i=1; i<=k; i++){
            for(int j=1; j<n; j++){
                b[j]=b[j-1];
                for(int l=0; l<j; l++){
                    b[j]=max(b[j], a[l]+arr[j]-arr[l]);
                }
            }
            for(int i=0; i<n; i++){
                a[i]=b[i];
            }
        }
        return b[n-1];
    }
};