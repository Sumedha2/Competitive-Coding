void reverse(int arr[], int i, int j){
    int l=i, r=j;
    while(l<r){
        int temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        l++;
        r--;
    }
}

void rotate(int arr[], int n)
{
    reverse(arr, 0, n-2);
    reverse(arr, 0, n-1);
}