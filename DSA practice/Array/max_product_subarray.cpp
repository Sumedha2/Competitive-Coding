//approach 1
class Solution{
public:

	long long max(long long a, long long b){
	    if(a>b){
	        return a;
	    }
	    return b;
	}
	long long maxProduct(vector<int> arr, int n) {
	    long long maxpro=INT_MIN, currpro=1;
	    for(int i=0; i<n; i++){
	        currpro*=arr[i];
	        maxpro=max(maxpro, currpro);
	        if(currpro==0){
	            currpro=1;
	        }
	    }
	    currpro=1;
	    for(int i=n-1; i>=0; i--){
	        currpro*=arr[i];
	        maxpro=max(maxpro, currpro);
	        if(currpro==0){
	            currpro=1;
	        }
	    }
	    if(n==1){
	        maxpro=arr[0];
	    }
	    return maxpro;
	}
};

// approach 2
//User function template for C++
class Solution{
public:

	long long max(long long a, long long b, long long c){
	    if(a>b){
	        if(a>c){
	            return a;
	        }
	        return c;
	    }
	    else{
	        if(b>c){
	            return b;
	        }
	        return c;
	    }
	}
	long long maxProduct(vector<int> arr, int n) {
	    long long l=1, h=1, ans=INT_MIN;
	    for(int i=0; i<n; i++){
	        l*=arr[i];
	        h*=arr[n-1-i];
	        ans=max(ans, l, h);
	        if(l==0){
	            l=1;
	        }
	        if(h==0){
	            h=1;
	        }
	    }
	    return ans;
	}
};