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
ll getter(ll a,ll b,map<ll,ll>&m){
    ll i=a,j=b,ans=-1;
    while(i<=j){
        ll mid=j-((j-i)/2);
        cout<<mid<<" ";
        if(m[mid]==0){
            ans=mid;
            j=mid-1;
        }else{
            i=mid+1;
        }
    }
    return ans;
}
void solve(){

ll n,a,b,k,sum=0,ans=0,mx=0,mn=1000000;
cin>>a>>b>>n;
vector<ll>v,op;
map<ll,ll>m;
v.pb(1);
mx=max(a,b);
mn=min(b,a);
//cout<<mx<<" ";
m[1]=1;
k=abs(a-b);
for(int y=1;y<n;y++){
    for(int o=0;o<v.size();o++){
       for(int i=0;i<v.size();i++){
        m[a*v[o]-b*v[i]]=1;
        m[b*v[o]-a*v[i]]=1;
    } 
    }
    ll i=v[v.size()-1]+1,sum=(mx*v[v.size()-1])-mn;
   ll flag=1;
    for(int u=i;u<=sum+1;u++){
        if(m[u]==0){
            flag=0;
            m[u]=1;
            v.pb(u);
            break;
        }
    }
    if(flag){
        v.pb(i);
        m[i]=1;
    }
}
for(int y=0;y<v.size();y++){
    cout<<v[y]<<" ";
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