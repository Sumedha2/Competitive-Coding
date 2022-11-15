#include <iostream>
using namespace std;

int *union_(int *a, int *b, int*c, int m, int n){
   int i=0, j=0, k=0;
   while(i<m && j<n){
      if(a[i]<b[j]){
         c[k++]=a[i++];
      }
      else if(b[j]<a[i]){
         c[k++]=b[j++];
      }
      else{
         c[k++]=a[i++];
         j++;
      }
   }
   for(;i<m;i++){
      c[k++]=a[i];
   }
   for(;j<n;j++){
      c[k++]=b[j];
   }
   return c;
}

int *intersection(int *a, int *b, int *d, int m, int n){
   int i=0, j=0, k=0;
   while(i<m && j<n){
      if(a[i]<b[j]){
         i++;
      }
      else if(b[j]<a[i]){
         j++;
      }
      else if(a[i]==b[j]){
         d[k++]=a[i++];
         j++;
      }
   }
   return d;

}

int *difference(int *a, int *b, int *e, int m, int n){
   int i=0, j=0, k=0;
   while(i<m && j<n){
      if(a[i]<b[j]){
         e[k++]=a[i++];
      }
      else if(b[j]<a[i]){
         j++;
      }
      else{
         i++; j++;
      }
   }
   for(;i<m; i++){
      e[k++]=a[i];
   }
   return e;
}

int main(){
   int m, n, a[10], b[10], c[20], d[10], e[10];
   cout<<"enter the number of elements of array 1: ";
   cin>>m;
   cout<<"enter the elements of array 1: ";
   for(int i=0; i<m; i++){
      cin>>a[i];
   }
   cout<<"enter the number of elements of array 2: ";
   cin>>n;
   cout<<"enter the elements of array 2: ";
   for(int i=0; i<n; i++){
      cin>>b[i];
   }
   int *u=union_(a, b, c, m, n);
   cout<<"the union is: ";
   int su=0;
   while(u[su]!=0){
      cout<<u[su]<<" ";
      su++;
   }
   cout<<endl;
   int *in=intersection(a, b, d, m, n);
   cout<<"the intersection is: ";
   int s=0;
   while(in[s]!=0){
      cout<<in[s]<<" ";
      s++;
   }
   cout<<endl;
   int *diff=difference(a, b, e, m, n);
   cout<<"the difference is: ";
   int sum=0;
   while(diff[sum]!=0){
      cout<<diff[sum]<<" ";
      sum++;
   }
   
}
