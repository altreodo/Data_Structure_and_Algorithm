#include<iostream>
using namespace std;
int sum(int a[],int m,int k){
    if(k==m-1){
        return a[k];
    }
        return max(a[k]+sum(a,m,k+1),sum(a,m,k+1));
}
int main(){
int n;
cin>>n;
int a[n];
for(int m=0;m<n;m++){
    cin>>a[m];
}
cout<<sum(a,n,0);
return 0;
}