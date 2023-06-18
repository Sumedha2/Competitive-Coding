
// approach 1

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        sort(a, a+n);
        sort(b, b+m);
        int i=0, j=0, c=0, s=m+n;
        while(i<n && j<m){
            if(a[i]<b[j]){
                i++;
            }
            else if(a[i]>b[j]){
                j++;
            }
            else{
                i++;
                j++;
                c++;
            }
        }
        return s-c;
    }   
};

// appraoch 2

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        map <int, int> mp;
        for(int i=0; i<n; i++){
            mp.insert({a[i], i});
        }
        for(int i=0; i<m; i++){
            mp.insert({b[i], i});
        }
        return mp.size();
    }   
};