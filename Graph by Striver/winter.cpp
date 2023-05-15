#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
void setter(int**g,int n,int y,bool*visi){
    y--;
    visi[y]=true;
    for(int s=0;s<n;y++){
        if(s!=(y) && g[y][s]==1 && !visi[s]){
            dp.push_back(s);
        }
    }
}
void marker(bool *visi){
    for(int y=0;y<dp.size();y++){
        visi[dp[y]]=true;
    }
    return;
}
int main(){
int n,e,q,t=0;
cin>>n>>e>>q;
int **edges=new int*[n];
for(int x=0;x<n;x++){
edges[x]=new int[n];
for(int y=0;y<n;y++){
edges[x][y]=0;
}
}
for(int y=0;y<e;y++){
int f,s;
cin>>f>>s;
edges[f-1][s-1]=1;
edges[s-1][f-1]=1;
}
bool * visited=new bool[n];
for(int y=0;y<n;y++){
    visited[y]=false;
}
for(int y=0;y<q;y++){
    int x,yt;
    cin>>x>>yt;
    if(x==1){
        setter(edges,n,yt,visited);
    }else if(x==2){
        marker(visited);
        dp.clear();
    }else{
        if(visited[yt-1]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
return 0;
}