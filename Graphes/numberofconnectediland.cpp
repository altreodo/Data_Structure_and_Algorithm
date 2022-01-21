#include<bits/stdc++.h>
using namespace std;
void pBFS(int **edges,int n,int sv,bool* visited){
    queue<int>q;
    q.push(sv);
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
            visited[y]=true;
            q.push(y);
        }
        }
    }
}
int BFS(int**edges,int n){
    int count=0;
bool* visited=new bool[n];
for(int y=0;y<n;y++){
    visited[y]=false;
}
for(int u=0;u<n;u++){
    if(!visited[u]){
    pBFS(edges,n,u,visited);  
    count++;
    }
}
return count;
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
cout<<BFS(edges,n);
return 0;
}