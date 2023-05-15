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
    //rank[y]=0;
    }
}
int getparent(int u){
    if(u==parent[u])return u;
    return parent[u]=getparent(parent[u]);
}
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
int main(){
int n,m;
DSU obj=DSU(5); 
return 0;
}