 #include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll getter(vector<pair<ll,ll>>&v,ll i,ll j){
    ll sum=0;
    for(ll y=0;y<v.size();y++){
    if(v[y].first+(i*1LL*v[y].second)>=j){
        sum+=v[y].first+(i*1LL*v[y].second);
    }
    }
    return sum;
}
int main(){
ll n,k,m,sum=0,ans=0,mx=0,po=1e18;
cin>>n>>k>>m;
vector<pair<ll,ll>>v(n);
for(int y=0;y<n;y++){
    ll a,b;
    cin>>a>>b;
    v[y]={a,b};
    //cout<<a<<" "<<b;
    if(k>v[y].first){
    ll op=(k-v[y].first)/v[y].second;
    if((k-v[y].first)%v[y].second!=0){
        op++;
    }
    mx=max(op,mx);
    }
}
sum=mx;
//cout<<mx<<" ";
ll i=0;
while(i<=sum){
    ll mid=sum-((sum-i)/2);
    ll jp=getter(v,mid,m);
   // cout<<mid<<" "<<i<<"-"<<sum<<" "<<jp<<" : ";
    if(jp>=k){
        ans=mid;
        sum=mid-1;
    }else if(jp<k){
        i=mid+1;
    }else{
        sum=mid-1;
    }
}
cout<<ans<<endl;
return 0;
}