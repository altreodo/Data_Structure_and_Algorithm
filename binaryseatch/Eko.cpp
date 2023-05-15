 #include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
ll n,k,m,sum=0,ans=0,mx=0,po=1e18;
cin>>n>>k;
vector<ll>v(n);
for(int y=0;y<n;y++){
   cin>>v[y];
   mx=max(mx,v[y]);
}
ll i=0,j=mx;
while(i<=j){
    ll count=0;
    ll mid=j-((j-i)/2);
  //  cout<<mid<<" ";
    for(int y=0;y<v.size();y++){
        count+=max(ans,v[y]-mid);
    }
    if(count>=k){
        sum=mid;
        i=mid+1;
    }else{
        j=mid-1;
    }
}
cout<<sum<<endl;

return 0;
}