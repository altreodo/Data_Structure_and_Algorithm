#include<bits/stdc++.h>
using namespace std;
int dp(int k,vector<pair<int,int>> &v,int n){
     if(k==0 || (n==0)){
        return 0;
    }if(v[n-1].first<=k){
    return max(v[n-1].second+dp(k-v[n-1].first,v,n-1),dp(k,v,n-1));
    }
    else if(v[n-1].first>k){
        return dp(k,v,n-1);
    }
}
int main(){
vector<pair<int,int>>s;
int n,k,sum=0,m=0;
cin>>n>>k;
for(int i=0;i<n;i++){
    int a,b;
    cout<<"enter the weight and price"<<endl;
    cin>>a>>b;
    s.push_back({a,b});
}
cout<<dp(k,s,n);
return 0;
}