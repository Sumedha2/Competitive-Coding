class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(v.begin(), v.end());
		    int n=v.size();
		    int x=0;
		    if(n%2==0){
		        x=(v[n/2-1]+v[n/2])/2;
		    }
		    else{
		        x=v[n/2];
		    }
		    return x;
		}
};