#include<bits/stdc++.h>
using namespace std;
//Kahn's Algorthm
vector<int>v;
void kahnalgo(vector<vector<int>>&ed,int* ind,int n){
    for(int y=0;y<n;y++){
        if(ind[y]==0){
            queue<int>q;
            q.push(y);
            while(!q.empty()){
                int j=q.front();
                q.pop();
                for(auto it:ed[j]){
                        ind[it]--;
                    if(ind[it]==0){
                        q.push(it);
                    }
                }
                v.push_back(j);
            }
        }
    }
}
int main(){
int n,e;
cin>>n>>e;
vector<vector<int>>edges(n);
int* indegree=new int[n];
for(int y=0;y<n;y++){
    indegree[y]=0;
}
for(int y=0;y<n;y++){
int u,v;
cin>>u>>v;
edges[u].push_back(v);
indegree[v]++;
}
kahnalgo(edges,indegree,n);
for(int y=0;y<v.size();y++){
    cout<<v[y]<<" ";
}
return 0;
}