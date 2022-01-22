#include<bits/stdc++.h>
using namespace std;
int dp[10000]={-1};
int get(int ar[],int n,int i,int e){
    if(e>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int m=0;
    if(ar[i]<ar[e]){
        m=1;
    }
    dp[i]= max(m+get(ar,n,i,e+1),get(ar,n,i+1,e+1));
    return dp[i];
}
int main(){
int n;
cin>>n;
int ar[n];
for(int y=0;y<n;y++){
    cin>>ar[y];
}
cout<<get(ar,n,0,1);
return 0;
}