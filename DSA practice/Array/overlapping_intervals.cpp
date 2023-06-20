class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int j=0, i=1;
        for(; i<intervals.size(); i++){
            if(ans[j][1]>=intervals[i][0]){
                (ans[j][1])=max(intervals[i][1], ans[j][1]);
            }
            else{
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};