#include<bits/stdc++.h>
using namespace std;
int main(){
int n,mn=99999999,mx=-99999999,ans,op;
cin>>n;
vector<pair<int,int>>v(n);
for(int y=0;y<n;y++){
    int a,b;
    cin>>a>>b;
   // cout<<a<<" "<<b;
    v[y]={a,b};
    mx=max(a,mx);
    mn=min(mn,a);
  //  cout<<mx<<" "<<mn<<" ";
}
int i=mn,h=mx;
while(i<=h){
    int mid=(i+h)/2;
    int sum1=0,sum2=0;
    for(int y=0;y<v.size();y++){
        if(v[y].first<=mid){
            sum1=max(sum1,abs(mid-v[y].first)/v[y].second);
        }else{
            sum2=max(sum2,abs(mid-v[y].first)/v[y].second);
        }
    }
    ans=mid;
    op=max(sum1,sum2);
    if(sum1==sum2){
        break;
    }else if(sum1<sum2){
        i=mid+1;
    }else{
        h=mid-1;
    }
}
cout<<op<<endl;
return 0;
}