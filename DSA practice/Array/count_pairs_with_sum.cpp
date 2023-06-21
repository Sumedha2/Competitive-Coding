// approach 1
class Solution{   
public:
    int getPairsCount(int a[], int n, int k) {
        int c=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(a[i]+a[j]==k){
                    c++;
                }
            }
        }
        return c;
    }
};

// approach 2
class Solution{   
public:
    int getPairsCount(int a[], int n, int k) {
        unordered_map <int, int> mp;
        int c=0;
        for(int i=0; i<n; i++){
            int l=k-a[i];
            if(mp[l]){
                c+=mp[l];
            }
            mp[a[i]]++;
        }
        return c;
    }
};