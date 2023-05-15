 #include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
int main(){
ll n,k,count=0,ans=0,mx=0,po=1e18;
cin>>n;
k=n;
vector<vector<ll>>v;
v.pb({});
v.pb({});
v.pb({});
v.pb({});
vector<ll>lp,pl;
while(n--){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    v[0].pb(a);
    v[1].pb(b);
    v[2].pb(c);
    v[3].pb(d);
}
map<ll,ll>m;
for(ll y=0;y<k;y++){
    for(ll j=0;j<k;j++){
        lp.pb(v[0][y]+v[1][j]);
        pl.pb(v[2][y]+v[3][j]);
        m[(v[2][y]+v[3][j])]=1;
    //     for(int u=0;u<k;u++){
    //     ll i=0,j=k-1,op=v[0][y]+v[1][j]+v[2][u];
    //  //   cout<<v[3][y]<<" ";
    //     ll flag=1;
    //     while(i<=j && flag==1){
    //     ll mid=(j-((j-i)/2));
    //     if(v[3][mid]==-op){
    //         count++;
    //         flag=0;
    //     }else if(v[3][mid]<op){
    //         i=mid+1;
    //     }else{
    //         j=mid-1;
    //     }
    //     }
    //     }
    }
}
//sort(pl.begin(),pl.end());
for(ll y=0;y<lp.size();y++){
    //   ll i=0,j=pl.size()-1,op=-lp[y],ol=-1;
    //  //   cout<<v[3][y]<<" ";
    //     ll flag=1;
    //     while(i<=j && flag==1){
    //     ll mid=(j-((j-i)/2));
    //     if(pl[mid]==op){
    //         ol=mid;
    //         count++;
    //         flag=0;
    //     }else if(pl[mid]<op){
    //         i=mid+1;
    //     }else{
    //         j=mid-1;
    //     }
    //     }
    if(m[(-1*lp[y])]==1){
        count++;
        m[(-1*lp[y])]=0;
    }
        // if(ol!=-1){
        // pl[ol]=-999999999;
        // sort(pl.begin(),pl.end());
        // }
}
cout<<count<<endl;
return 0;
}