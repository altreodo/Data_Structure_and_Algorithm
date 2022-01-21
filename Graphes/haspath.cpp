#include<iostream>
using namespace std;
bool haspath(int **edges,int n,int sv,bool* visited,int end){
    visited[sv]=true;
     if( visited[end]){
        return true;
    }
    for(int y=0;y<n;y++){
        if(y==sv){
            continue;
        }
        if(edges[sv][y]==1){
            if(visited[y]){
                continue;
            }
            if(haspath(edges,n,y,visited,end)){
                return true;
            }
        }
    }
    return false;
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
if(haspath(edges,n,strt,visited,end)){
    cout<<"true"<<endl;
}else{
    cout<<"false"<<endl;
}
return 0;
}