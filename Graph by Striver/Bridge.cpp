#include<bits/stdc++.h>
using namespace std;
void dfs(int y,int j,vector<int>&vis,vector<int>&tin,vector<int>&low,int& timer,vector<vector<int>>&ed){
    vis[y]=1;
    low[y]=tin[y]=timer++;
   for(auto it:ed[y]){
       if(it==j)continue;
       if(!vis[it]){
           dfs(it,y,vis,tin,low,timer,ed);
           low[y]=min(low[y],low[it]);
           if(low[it]>tin[y]){
               cout<<y<<" "<<it<<endl;
           }
       }else{
           low[y]=min(low[y],tin[it]);
       }
   }
}
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>ed(n);
for(int y=0;y<m;y++){
int a,b;
cin>>a>>b;
ed[a].push_back(b);
ed[b].push_back(a);
}
vector<int>tin(n);
vector<int>low(n);
vector<int>vis(n);
int timer=0;
for(int y=0;y<n;y++){
    if(!vis[y]){
    dfs(y,-1,vis,tin,low,timer,ed);
    }
}
return 0;
}