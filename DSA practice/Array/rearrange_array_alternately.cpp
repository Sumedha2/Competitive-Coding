
// approach 1
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *a, int n) 
    { 
    	long long b[n];
    	int l=0, h=n-1;
    	int f=true;
    	for(int i=0; i<n; i++){
    	    if(i==0 || i%2==0){
    	        b[i]=a[h--];
    	    }
    	    else{
    	        b[i]=a[l++];
    	    }
    	}
    	for(int i=0; i<n; i++){
    	    a[i]=b[i];
    	}
    }
};

// approach 2
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *a, int n) 
    { 
    	int l=0, h=n-1, maxi=a[n-1]+1;
    	for(int i=0; i<n; i++){
    	    if(i%2==0){
    	        a[i]+=(a[h]%maxi)*maxi;
    	        h--;
    	    }
    	    else{
    	        a[i]+=(a[l]%maxi)*maxi;
    	        l++;
    	    }
    	}
    	for(int i=0; i<n; i++){
    	    a[i]=a[i]/maxi;
    	}
    }
};