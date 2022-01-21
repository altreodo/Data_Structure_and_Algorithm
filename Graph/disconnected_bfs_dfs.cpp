#include<bits/stdc++.h>
using namespace std;
void printBFS(int ** edges,int k,int sv,bool * visited){
    queue<int>q;
    q.push(sv);
    while(!q.empty()){
    int op=q.front();
    q.pop();
    if(!visited[op]){
    cout<<op<<" ";
    visited[op]=true;
    for(int i=0;i<k;i++){
        if(edges[op][i]==1){
            q.push(i);
        }
    }
    }
    }
}
void printDFS(int ** edges,int k,int sv,bool * visited){
    cout<<sv<<" ";
    visited[sv]=true;
    for(int y=0;y<k;y++){
        if(y==sv )continue;
     if(edges[sv][y]==1){
         if( visited[y])continue;
     printDFS(edges,k,y,visited);
     }
    }
}

void bfs(int ** edges,int k){
bool * visited=new bool[k];
for(int y=0;y<k;y++){
    visited[y]=false;
}
for(int y=0;y<k;y++){
if(!visited[y]){
    printBFS(edges,k,y,visited);
}
}
}
void dfs(int ** edges,int k){
bool * visited=new bool[k];
for(int y=0;y<k;y++){
    visited[y]=false;
}
for(int y=0;y<k;y++){
if(!visited[y]){
    printDFS(edges,k,y,visited);
}
}
delete [] visited;
}
int main(){
int n,e;
cin>>n>>e;
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
edges[f][s]=1;
edges[s][f]=1;
}

bfs(edges,n);
cout<<endl;
dfs(edges,n);
return 0;
}