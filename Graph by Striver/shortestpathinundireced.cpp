#include<bits/stdc++.h>
using namespace std;
void mindis(vector<vector<int>>&v,bool* vis,int i){
    vector<int>ans(v.size(),999999);
queue<pair<int,int>>q;
int dis=0;
q.push({i,dis});
while(!q.empty()){
    pair<int,int>op=q.front();
    //dis++;
    vis[op.first]=true;
    q.pop();
    for(auto it:v[op.first]){
        if(!vis[it]){
        q.push({it,op.second+1});
        vis[it]=true;
        }
    }
    ans[op.first]=op.second;
}
for(int y=0;y<ans.size();y++){
    cout<<ans[y]<<" ";
}
}
int main(){
int n, e,s;
    cin >> n >> e>>s;
    vector<vector<int>> edges(n);
    bool *visited = new bool[n];
    for (int y = 0; y < n; y++)
    {
        visited[y] = false;
    }
    for (int y = 0; y < e; y++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    mindis(edges,visited,s);
return 0;
}