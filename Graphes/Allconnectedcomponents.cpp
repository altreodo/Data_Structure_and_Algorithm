#include<bits/stdc++.h>
using namespace std;
vector<int> pBFS(int **edges,int n,int sv,bool* visited){
    queue<int>q;
    vector<int>v;
    q.push(sv);
    v.push_back(sv);
    visited[sv]=true;
    while(!q.empty()){
        int op=q.front();
        q.pop();
        for(int y=0;y<n;y++){
            if(y==op){
                continue;
            }
            if(edges[op][y]==1){
            if(visited[y]){
                continue;
            }
            v.push_back(y);
            visited[y]=true;
            q.push(y);
        }
        }
    }
    return v;
}
void BFS(int**edges,int n){
bool* visited=new bool[n];
for(int y=0;y<n;y++){
    visited[y]=false;
}
for(int u=0;u<n;u++){
    if(!visited[u]){
        vector<int>v;
    v=pBFS(edges,n,u,visited);  
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
cout<<endl;
    }
}
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
BFS(edges,n);
return 0;
}