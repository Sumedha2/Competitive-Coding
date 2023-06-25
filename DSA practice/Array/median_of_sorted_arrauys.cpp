class Solution{
    public:
    double MedianOfArrays(vector<int>& a1, vector<int>& a2)
    {
        vector<int> a;
        int m=a1.size(), n=a2.size(), i=0, j=0;
        while(i<m && j<n){
            if(a1[i]<a2[j]){
                a.push_back(a1[i]);
                i++;
            }
            else if(a1[i]>a2[j]){
                a.push_back(a2[j]);
                j++;
            }
            else{
                a.push_back(a1[i]);
                a.push_back(a2[j]);
                i++;
                j++;
            }
        }
        while(i<m){
            a.push_back(a1[i]);
            i++;
        }
        while(j<n){
            a.push_back(a2[j]);
            j++;
        }
        double x=0;
        int s=n+m;
        // for(int i=0; i<s; i++){
        //     cout<<a[i]<<" ";
        // }
        if(s%2==0){
            x=(a[s/2-1]+a[s/2])/2.0;
        }
        else{
            x=a[s/2];
        }
        return x;
    }
};