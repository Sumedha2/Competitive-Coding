class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int i=0, j=0, sum=arr[0], c=INT_MAX;
        while(j<n){
            if(sum<=x){
                j++;
                sum+=arr[j];
            }
            else{
                c=min(c, j-i+1);
                sum-=arr[i];
                i++;
            }
        }
        return c;
    }
};