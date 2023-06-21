class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            vector<int> ele;
            int i=0, j=0, k=0;
            while(i<n1 && j<n2 && k<n3){
                if(a[i]==b[j] && b[j]==c[k]){
                    ele.push_back(a[i]);
                    i++;
                    j++;
                    k++;
                }
                else if(a[i]<b[j]){
                    i++;
                }
                else if(b[j]<c[k]){
                    j++;
                }
                else{
                    k++;
                }
                int x=a[i-1], y=b[j-1], z=c[k-1];
                while(a[i]==x){
                    i++;
                }
                while(b[j]==y){
                    j++;
                }
                while(c[k]==z){
                    k++;
                }
            }
            if(ele.size()==0){
                return {-1};
            }
            return ele;
        }

};