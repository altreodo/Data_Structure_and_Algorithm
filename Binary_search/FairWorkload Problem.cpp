#include<bits/stdc++.h>
using namespace std;
int getter(vector<int>&v,int kp){
    int j=0,sum=0;
    for(int y=0;y<v.size();y++){
        sum+=v[y];
        if(sum>kp){
        j++;
        sum=v[y];
        }
    }
    j++;
    return j;
}
int main(){
int n,k,sum=0,ans=0;
cin>>n>>k;
vector<int>v(n);
for(int y=0;y<n;y++){
    cin>>v[y];
    sum+=v[y];
}
int i=0;
while(i<=sum){
    int mid=(i+sum)/2;
    int jp=getter(v,mid);
    if(jp==k){
        ans=mid;
        sum=mid-1;
    }else if(jp>k){
        i=mid+1;
    }else{
        sum=mid-1;
    }
}
cout<<ans<<endl;
return 0;
}