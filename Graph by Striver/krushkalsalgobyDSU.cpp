#include<bits/stdc++.h>
using namespace std;
class DSU{
public:
vector<int>rank;
vector<int>parent;
DSU(int n){
    parent.resize(n,0);
    rank.resize(n,0);
for(int y=0;y<n;y++){
    parent[y]=y;
    rank[y]=0;
    }
}
int getparent(int u){
    if(u==parent[u])return u;
    return parent[u]=getparent(parent[u]);
}
//UNION DSU ADDER 
void unionDSU(int u,int v){
    int a=getparent(u);
    int b=getparent(v);
    if(rank[a]>rank[b]){
        parent[b]=a;
    }else if(rank[a]<rank[b]){
        parent[a]=b;
    }else{
        parent[a]=b;
        rank[b]++;
    }
}
};
void krushkalsalgo(vector<pair<int,pair<int,int>>>&edges,int n){
DSU obj=DSU(n);
vector<pair<int,pair<int,int>>>ans;
for(int y=0;y<edges.size();y++){
int a=edges[y].second.second;
int b=edges[y].second.first;
int w=edges[y].first;
if(obj.getparent(a)!=obj.getparent(b)){
     pair<int,int>p={b,w};
    ans.push_back({a,p});
    obj.unionDSU(a,b);
}
}
for(auto x:ans){
    cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
} 
}
int main(){
int n, e,s;
    cin >> n >> e;
vector<pair<int,pair<int,int>>> edges(e);
    for (int y = 0; y < e; y++)
    {
        int u, v,w;
        cin >> u >> v>>w;
        pair<int,int>p={u,v};
        edges.push_back({w,p});
    }
    sort(edges.begin(),edges.end());
    krushkalsalgo(edges,n);
return 0;
}
