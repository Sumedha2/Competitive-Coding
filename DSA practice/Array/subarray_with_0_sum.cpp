// approach 1
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        map<int, int> m;
        int s=0;
        for(int i=0; i<n; i++){
            s+=arr[i];
            m[s]++;
            if(m[s]>1 || s==0){
                return true;
            }
        }
        return false;
    }
};


// approach 2
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, int> m;
        int s=0;
        for(int i=0; i<n; i++){
            s+=arr[i];
            m[s]++;
            if(m[s]>1 || s==0){
                return true;
            }
        }
        return false;
    }
};