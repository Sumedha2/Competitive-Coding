class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        int temp[n], j=0;
        for(int i=0; i<n; i++){
            if(arr[i]>=0){
                temp[j++]=arr[i];
            }
        }
        for(int i=0; i<n; i++){
            if(arr[i]<0){
                temp[j++]=arr[i];
            }
        }
        memcpy(arr, temp, sizeof(temp));
    }
};