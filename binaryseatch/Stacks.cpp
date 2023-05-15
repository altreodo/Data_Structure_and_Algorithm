 #include<bits/stdc++.h>
#define  ull unsigned long long int
#define ll long long 
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
#define pb push_back
#define Setbit(n)   __builtin_popcountll(n)
#define ms(a,x) memset(a,x,sizeof(a))
#define sp(n,a) cout<<fixed<<setprecision(n)<<a
#define maxa(a,n) *max_element(a,a+n)
#define mina(a,n) *min_element(a,a+n)
#define aca(a,n,x) accumulate(a,a+n,x)
#define pi 3.14159265358979323846
const ull INF=1e18; 
const  ll  N=200007;
using namespace std;
int64_t lol;
#define MOD 998244353
#define MAX  10000000


//
 //ll arr[1000000]={-1};
// ms(arr,0);

void solve(){

ll n,k,m,sum=0,ans=0,mx=0,po=1e18;
cin>>n;
vector<ll>v(n),op;
for(int y=0;y<n;y++){
    cin>>v[y];
}
op.pb(v[0]);
//cout<<mx<<" ";
for(int y=1;y<n;y++){
    ll i=0,sum=op.size()-1;
    ans=-1;
while(i<=sum){
    ll mid=sum-((sum-i)/2);
   // cout<<mid<<" "<<i<<"-"<<sum<<" "<<jp<<" : ";
    if(op[mid]>v[y]){
        ans=mid;
        sum=mid-1;
    }else{
        i=mid+1;
    }
}
    if(ans==-1){
        op.pb(v[y]);
    }else{
        op[ans]=v[y];
    }
}
cout<<op.size()<<" ";
for(int y=0;y<op.size();y++){
    cout<<op[y]<<" ";
}
cout<<endl;
}

int  main(){

ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
int t,m=1;
cin>>t;

//cout<<v.size()<<" ";
//t=1;
while(t--){
solve();
m++;
}
return 0;
}