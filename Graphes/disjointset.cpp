#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> rank, parent;
    public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    
    void unionParent(int u, int v){
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(rank[parU] < rank[parV]){
            parent[parU] = parV;
        }
        else if(rank[parV] < rank[parU]){
            parent[parV] = parU;
        }
        else if(rank[parU] == rank[parV]){
            parent[parU] = parV;
            rank[parV] += 1;
        }
    }
};
int main(){

return 0;
}