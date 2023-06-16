

// approach 2
class Solution
{
    public:
    // void swap(int* x, int* y){
    //     int temp=*x;
    //     *x=*y;
    //     *y=temp;
    // }
    void sort012(int a[], int n)
    {
        long long int l=0, mid=0, h=n-1;
        while(mid<=h){
            if((a[mid])==0){
                swap(a[mid], a[l]);
                mid++;
                l++;
            }
            else if(a[mid]==1){
                mid++;
            }
            else{
                swap(a[mid], a[h]);
                h--;
                mid;
            }
        }
    }
};

// approach 1
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int z=0, o=0, t=0;
        for(int i=0; i<n; i++){
            if(a[i]==0){
                z++;
            }
            else if(a[i]==1){
                o++;
            }
            else{
                t++;
            }
        }
        
        for(int i=0; i<z; i++){
            a[i]=0;
        }
        
        for(int i=z; i<o+z; i++){
            a[i]=1;
        }
        
        for(int i=o+z; i<n; i++){
            a[i]=2;
        }
    }
    
};