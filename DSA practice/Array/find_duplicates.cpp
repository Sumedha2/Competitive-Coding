class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> ans;
        int h[n]={0};
        for(int i=0; i<n; i++){
            h[arr[i]]++;
        }
        for(int i=0; i<n; i++){
            if(h[i]>1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0){
            ans.push_back(-1);
        }
        return ans;
    }
};