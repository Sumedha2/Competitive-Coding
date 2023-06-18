// approach 1

class Solution{
  public:
    int minJumps(int arr[], int n){
        for(int i=1; i<n; i++){
            ((arr[i]+i)>arr[i-1])?arr[i]=arr[i]+i:arr[i]=arr[i-1];
            // arr[i]=max(arr[i]+i, arr[i-1]);
        }
        int index=0, ans=0;
        while(index<=n){
            ans++;
            index=arr[index];
        }
        return ans;
    }
};



// approach 2

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n<=1){
            return 0;
        }
        if(arr[0]==0){
            return -1;
        }
        int maxreach=arr[0], step=arr[0], jump=1;
        for(int i=1; i<n; i++){
            if(i==n-1){
                return jump;
            }
            maxreach=max(maxreach, arr[i]+i);
            step--;
            if(step==0){
                jump++;
                if(i>=maxreach){
                    return -1;
                }
                step=maxreach-i;
            }
        }
        return -1;
    }
};

