#include<bits/stdc++.h>
using namespace std;
int mah(int ar[],int n){
    int mx=-1;
    stack<pair<int,int>>s,s2;
    vector<int>v1,v2;
    for(int y=0;y<n;y++){
        if(s.size()==0){
            v1.push_back(-1);
        }else if(s.size()>0 && s.top().first<ar[y]){
            v1.push_back(s.top().second);
        }else{
            while(s.size()>0 && s.top().first>=ar[y]){
                s.pop();
            }
            if(s.size()==0){
                v1.push_back(-1);
            }else{
                v1.push_back(s.top().second);
            }
        }
        s.push({ar[y],y});
    }
    for(int y=n-1;y>=0;y--){
        if(s2.size()==0){
            v2.push_back(n);
        }else if(s2.size()>0 && s2.top().first<ar[y]){
            v2.push_back(s2.top().second);
        }else{
            while(s2.size()>0 && s2.top().first>=ar[y]){
                s2.pop();
            }
            if(s2.size()==0){
                v2.push_back(n);
            }else{
                v2.push_back(s2.top().second);
            }
        }
        s2.push({ar[y],y});
    }
    reverse(v2.begin(),v2.end());
for(int y=0;y<n;y++){
    mx=max(mx,(v2[y]-v1[y]-1)*ar[y]);
}
return mx;
}
int main(){
int n,m,mx=-1;
cin>>n>>m;
int ar[m]={0},arr[n][m];
for(int y=0;y<n;y++){
    for(int h=0;h<m;h++){
        cin>>arr[y][h];
    }
}
for(int y=0;y<n;y++){
    for(int h=0;h<m;h++){
        if(arr[y][h]==0){
            ar[h]=0;
        }else{
        ar[h]+=arr[y][h];
        }
    }
    mx=max(mx,mah(ar,m));
}
cout<<mx;
return 0;
}