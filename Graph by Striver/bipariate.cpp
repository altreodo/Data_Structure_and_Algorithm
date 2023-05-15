#include<bits/stdc++.h>
using namespace std;
bool bipariatebfs(vector<vector<int>>edges,int n,int *vis){
    int flag=0;
    for(int y=1;y<=n;y++){
       if(vis[y]==-1){
       queue<pair<int,int>>q;
       q.push({y,0});
       vis[y]=0;
       while(!q.empty()){
           pair<int,int>op=q.front();
           q.pop();
           int m=1;
           if(op.second==1){
               m=0;
           }
       for(auto it:edges[op.first]){
           if( vis[it]==op.second)flag=1;
           else if(vis[it]==-1){
               q.push({it,m});
           vis[it]=m;
           }
       }
       }
       }
    }
    return flag;
}
int main(){
int n,e;
cin>>n>>e;
vector<vector<int>>edges(n+1);
for(int y=0;y<n;y++){
int u,v;
cin>>u>>v;
edges[u].push_back(v);
edges[v].push_back(u);
}
int * visited=new int[n+1];
for(int y=1;y<=n;y++){
    visited[y]=-1;
}
if(bipariatebfs(edges,n,visited)){
    cout<<"No"<<endl;
}else{
    cout<<"Yes"<<endl;
}for(int y=1;y<=n;y++){
    cout<<visited[y]<<" ";
}
return 0;
}