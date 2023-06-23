class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long long water=0;
        int i=0, j=n-1, l=0, r=0;
        while(i<=j){
            if(arr[i]<=arr[j]){
                if(arr[i]>=l){
                    l=max(l, arr[i]);
                }
                else{
                    water+=l-arr[i];
                }
                i++;
            }
            else{
                if(arr[j]>=r){
                    r=max(r, arr[j]);
                }
                else{
                    water+=r-arr[j];
                }
                j--;
            }
        }
        return water;
    }
};