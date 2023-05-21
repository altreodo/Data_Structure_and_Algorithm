#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,flag=0;
cin>>n>>m;
vector<vector<int>>edges(n+1);
for(int y=0;y<m;y++){
int u,v;
cin>>u>>v;
edges[u].push_back(v);
edges[v].push_back(u);
}
vector<int>vis(n+2,0);
for(int y=1;y<=n;y++){
    if(!vis[y]){
        vis[y]=1;
        queue<pair<int,int>>q;
        q.push({y,-1});
        while(!q.empty()){
            pair<int,int>k=q.front();
            q.pop();
            for(auto it :edges[k.first]){
            if(!vis[it]){
                q.push({it,y});
                vis[it]=1;
            }else{
                if(it!=y){
                    flag=1;
                }
            }
            }
        }
    }
}
if(flag){
    cout<<"Yes it has cycle"<<endl;
}else{
    cout<<"NO it does not have cycle"<<endl;
}
}