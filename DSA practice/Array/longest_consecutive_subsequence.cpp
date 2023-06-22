// approach 1
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      sort(arr, arr+n);
      int c=1, maxc=1;
      for(int i=0; i<n-1; i++){
          if((arr[i+1]-arr[i])==1){
              c++;
              maxc=max(c, maxc);
          }
          else if ((arr[i+1]-arr[i])>1){
              c=1;
          }
      }
      return maxc;
    }
};

// approach 2
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      unordered_set<int> s;
      for(int i=0; i<n; i++){
          s.insert(arr[i]);
      }
      int ans=0;
      for(int i=0; i<n; i++){
          if(s.find(arr[i]-1)==s.end()){
              int c=0, start=arr[i];
              while(s.find(start)!=s.end()){
                  c++;
                  start++;
              }
              ans=max(ans, c);
          }
      }
      return ans;
    }
};