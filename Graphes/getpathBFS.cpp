#include<bits/stdc++.h>
using namespace std;
map<int,int> getpath(int**edges,int n,int sv,int end,bool* visited,map<int,int>&v,int l,queue<int>&q){
    q.push(sv);
    v.insert({sv,-1});
while(!q.empty()){
    int op=q.front();
    q.pop();
visited[op]=true;
for(int y=0;y<n;y++){
    if(edges[op][y]==1 && !visited[y]){
        v.insert({y,op});
        q.push(y);
        visited[y]=true;
       // break;
    }
    if(visited[end]==true){
       // q.erase();
        break;
    }
}
l=op;
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
for (int i = 0; i < e; i++)
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
int strt,end,op=0;
cin>>strt>>end;
map<int,int>v;
queue<int>q;
v=getpath(edges,n,strt,end,visited,v,-1,q);
if(v.size()>1){
//cout<<strt<<" ";
}
map<int,int>::iterator i=v.begin();
while(end!=-1 && v.size()>2){
    cout<<end<<" ";
    end=v[end];
}
return 0;
}