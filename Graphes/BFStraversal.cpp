#include<bits/stdc++.h>
using namespace std;
void print(int **edges,int n,int sv,bool* visited){
    queue<int>q;
    q.push(sv);
    cout<<sv<<" ";
    visited[sv]=true;
    while(!q.empty()){
        int op=q.front();
        q.pop();
        for(int y=0;y<n;y++){
            if(edges[op][y]==1){
            if(visited[y]){
                continue;
            }
            cout<<y<<" ";
            visited[y]=true;
            q.push(y);
        }
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
bool *visited=new bool[n];
for(int i=0;i<n;i++){
    visited[i]=false;
}
print(edges,n,0,visited);
return 0;
}