#include<bits/stdc++.h>
using namespace std;
//TIME COMPLEXCITY O(N+E)

stack<int>s;
void dfs(vector<vector<int>>&ed,bool* vis,int i){
if(!vis[i]){
    vis[i]=true;
for(auto it:ed[i]){
if(!vis[it]){
    dfs(ed,vis,it);
}
}
s.push(i);
}
}
int main(){
int n,e;
cin>>n>>e;




vector<vector<int>>edges(n);
for(int y=0;y<n;y++){
int u,v;
cin>>u>>v;
edges[u].push_back(v);
}
bool * visited=new bool[n];
for(int y=0;y<n;y++){
    visited[y]=false;
}
for(int y=0;y<n;y++){
dfs(edges,visited,y);
}
while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
}
return 0;
}