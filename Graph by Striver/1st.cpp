#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>edges(n+1);
for(int y=0;y<m;y++){
int u,v;
cin>>u>>v;
edges[u].push_back(v);
edges[v].push_back(u);
}
vector<int>vis(n+1,0),bfs;
for(int y=1;y<=n;y++){
    if(!vis[y]){
        queue<int>q;
        q.push(y);
       // bfs.push_back(y);
        vis[y]=1;
        while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: edges[node]){
            if(!vis[it]){
        q.push(it);
        vis[it]=1;
            }
        }
        }
    }
}
for(auto it:bfs){
    cout<<it<<" ";
}

return 0;
}