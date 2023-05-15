#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
ll n,k,m=0,ans=0;
cin>>n>>k;
vector<ll>v(n);
for(ll y=0;y<n;y++){
    cin>>v[y];
}
sort(v.begin(),v.end());
ll i=0,j=1e9,mn;
while(i<=j){
    ll mid=(i+j)/2;
   // cout<<mid<<" "<<i<<" "<<j<<" "; 
    ll po=v[0]+mid,sum=1,mn=99999999;
    for(int y=1;y<v.size();y++){
        if(v[y]>=po){
            po=mid+v[y];
            sum++;
        }
    }
    if(sum>=k){
        ans=mid;
        i=mid+1;
    }else if(sum<k){
        j=mid-1;
    }else{
        i=mid+1;
    }
}
cout<<ans<<endl;
    }
return 0;
}