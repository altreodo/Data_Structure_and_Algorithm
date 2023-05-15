#include<bits/stdc++.h>
using namespace std;
//Weighted graph
stack<int>s;
void topologicalsortdfs(vector<vector<pair<int,int>>>&v,bool* vis,int j){
        if(!vis[j]){
            vis[j]=true;
            for(auto it:v[j]){
                if(!vis[it.first]){
        topologicalsortdfs(v,vis,it.first);
        }
            }
    s.push(j);
        }
}
void mindis(vector<vector<pair<int,int>>>&v,bool* vis,int src){
    vector<int>min_dis(v.size(),INT_MAX);
    min_dis[src]=0;
    while(!s.empty()){
        int k=s.top();
       // cout<<k<< " ";
        s.pop();
        if(min_dis[k]!=INT_MAX){
            for(auto it: v[k]){
                min_dis[it.first]=min(min_dis[it.first],it.second+min_dis[k]);
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<min_dis[i]<<" ";
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
    }
    topologicalsortdfs(edges,visited,0);
    mindis(edges,visited,s);
return 0;
}