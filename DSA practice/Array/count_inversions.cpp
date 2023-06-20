// brute force

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long a[], long long n)
    {
        int c=0;
        for(int i=0; i<n-1; i++){
            for(int j=i; j<n; j++){
                if(a[i]>a[j]){
                    c++;
                }
            }
        }
        return c;
    }

};

// optimal
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long a[], long long n)
    {
        return mergesort(a, 0, n-1);
    }
    long long mergesort(long long a[], long long l, long long h){
        long long c=0;
        if(l<h){
            long long mid=l+(h-l)/2;
            c+=mergesort(a, l, mid);
            c+=mergesort(a, mid+1, h);
            c+=merge(a, l, mid, h);
        }
        return c;
    }
    long long merge(long long a[], long long l, long long mid, long long h){
        long long res=0;
        long long n1=mid-l+1, n2=h-mid;
        long long a1[n1], a2[n2];
        for(long long i=0; i<n1; ++i){
            a1[i]=a[l+i];
        }
        for(long long i=0; i<n2; ++i){
            a2[i]=a[mid+i+1];
        }
        long long i=0, j=0, k=l;
        while(i<n1 && j<n2){
            if(a1[i]<=a2[j]){
                a[k++]=a1[i++];
            }
            else{
                a[k++]=a2[j++];
                res+=n1-i;
            }
        }
        while(i<n1){
            a[k++]=a1[i++];
        }
        while(j<n2){
            a[k++]=a2[j++];
        }
        return res;
    }

};