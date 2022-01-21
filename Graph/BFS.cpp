#include<bits/stdc++.h>
using namespace std;
void print(int ** edges,int k,int sv,bool * visited){
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
bool * visited=new bool[n];
for(int y=0;y<e;y++){
    visited[y]=false;
}
print(edges,n,0,visited);
return 0;
}