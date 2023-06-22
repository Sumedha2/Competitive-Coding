class Solution {
public:
    vector<int> factorial(int n){
        vector<int> ans;
        ans.push_back(1);
        for(int j=2; j<=n; j++){
            int carr=0;
            for(int i=0; i<ans.size(); i++){
                int val=ans[i]*j+carr;
                ans[i]=val%10;
                carr=val/10;
            }
            while(carr!=0){
                ans.push_back(carr%10);
                carr/=10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};