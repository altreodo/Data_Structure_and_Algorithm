#include<bits/stdc++.h>
using namespace std;
vector<int> getpath(int**edges,int n,int sv,int end,bool* visited,vector<int>&v){
if(sv==end){
    for(int m=0;m<n;m++){
        visited[m]=true;
    }
    v.push_back(end);
    return v;
}
v.push_back(sv);
visited[sv]=true;
for(int y=0;y<n;y++){
    if(edges[sv][y]==1 && !visited[y]){
        v=getpath(edges,n,y,end,visited,v);
    }
}
return v;
}
int main(){
int n,e;
cin>>n>>e;
 int **edges=new int*[n];
for(int i=0;i<n;i++){
   edges[i]=new int[n];
   for(int y=0;y<n;y++){
       edges[i][y]=0;
   }
}
for ( int i = 0; i < e; i++)
{
    int f,e;
    cin>>f>>e;
    edges[f][e]=1;
    edges[e][f]=1;
}
bool *visited=new bool[n];
for(int i=0;i<n;i++){
    visited[i]=false;
}
int strt,end;
cin>>strt>>end;
vector<int>v;
v=getpath(edges,n,strt,end,visited,v);
if(v[v.size()-1]==end){
for(int y=0;y<v.size();y++){
    cout<<v[y]<<" ";
}
}
return 0;
}