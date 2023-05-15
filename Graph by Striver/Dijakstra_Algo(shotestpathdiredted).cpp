#include<bits/stdc++.h>
using namespace std;
void Dijaskstraalgo(vector<vector<pair<int,int>>>&v,int i){
priority_queue<pair<int,int>>q;
vector<int>min_dis(v.size(),INT_MAX);
min_dis[i]=0;
q.push({0,i});
while(!q.empty()){
    pair<int,int>op=q.top();
    q.pop();
    for(auto it:v[op.second]){
        if(min_dis[it.first]>op.first+it.second){
        min_dis[it.first]=op.first+it.second;
        q.push({min_dis[it.first],it.first});
        }
    }
} 
for (int y = 0; y < min_dis.size(); y++)
    {
       cout<<min_dis[y]<<" ";
    }
}
int main(){
int n, e,s;
    cin >> n >> e>>s;
    vector<vector<pair<int,int>>> edges(n);
    bool *visited = new bool[n];
    for (int y = 0; y < n; y++)
    {
        visited[y] = false;
    }
    for (int y = 0; y < e; y++)
    {
        int u, v,w;
        cin >> u >> v>>w;
        edges[u].push_back({v,w});
         edges[v].push_back({u,w});
    }
    Dijaskstraalgo(edges,s);
return 0;
}