class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int n=arr.size();
        int l=0, r=n-1;
        for(int i=0; i<=r; i++){
            if(arr[i]<a){
                swap(arr[l++], arr[i]);
            }
            else if(arr[i]>b){
                swap(arr[i--], arr[r--]);
            }
        }
    }
};