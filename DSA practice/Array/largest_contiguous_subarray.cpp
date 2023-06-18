// easy approach brute

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long int maxsum=-1e9;
        for(int i=0; i<n; i++){
            int currsum=0;
            for(int j=i; j<n; j++){
                currsum+=arr[j];
                if(currsum>maxsum){
                    maxsum=currsum;
                }
            }
        }
        return maxsum;
        
    }
};


// kadane's algorithm

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long int maxsum=-1e9;
        for(int i=0; i<n; i++){
            int currsum=0;
            for(int j=i; j<n; j++){
                currsum+=arr[j];
                if(currsum>maxsum){
                    maxsum=currsum;
                }
            }
        }
        return maxsum;
        
    }
};