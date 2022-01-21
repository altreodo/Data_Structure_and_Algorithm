#include<iostream>
using namespace std;
void print(int ** edges,int k,int sv,bool * visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int y=0;y<k;y++){
        if(y==sv )continue;
     if(edges[sv][y]==1){
         if( visited[y])continue;
     print(edges,k,y,visited);
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