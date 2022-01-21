#include<bits/stdc++.h>
using namespace std;
void check(int **edges,int n,int sv,bool* visited){
    queue<int>q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int op=q.front();
        q.pop();
        for(int y=0;y<n;y++){
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
bool isconnected(bool* visited,int n){
    for(int y=0;y<n;y++){
        if(visited[y]==false){
            return false;
        }
    }
    return true;
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
check(edges,n,0,visited);
if(isconnected(visited,n)){
    cout<<"true";
}else{
    cout<<"false";
}
return 0;
}