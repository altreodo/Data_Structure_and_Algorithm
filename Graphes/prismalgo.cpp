#include<bits/stdc++.h>
using namespace std;
int findmin(int*weight,bool*visited,int n){
    int minvertex=-1;
    for(int y=0;y<n;y++){
        if(!visited[y] &&(minvertex==-1 || weight[y]<weight[minvertex])){
            minvertex=y;
        }
    }
    return minvertex;
}
void prismalgo(int ** edges,int n){
    int* parent=new int[n];
    int* weights=new int[n];
    bool* visited=new bool[n];
    for(int y=0;y<n;y++){
        visited[y]=false;
        weights[y]=INT_MAX;
    }
    parent[0]=-1;
    weights[0]=0;
    for(int y=0;y<n;y++){
        int minvertex=findmin(weights,visited,n);
        visited[minvertex]=true;
        for(int y=0;y<n;y++){
            if(edges[minvertex][y]!=0 && !visited[y]){
                if(edges[minvertex][y]<weights[y]){
                weights[y]=edges[minvertex][y];
                parent[y]=minvertex;
                }
            }
        }
    }
    cout<<"MST---->"<<endl;
    for(int i=1;i<n;i++){
        cout<<min(i,parent[i])<<" "<<max(i,parent[i])<<" "<<weights[i]<<endl;
    }
}
int main(){
int n,e;
cin>>n>>e;
int** edges=new int*[n];
for(int i=0;i<n;i++){
    edges[i]=new int[n];
    for(int y=0;y<n;y++){
        edges[i][y]=0;
    }
}
while(e--){
    int f,s,w;
    cin>>f>>s>>w;
    edges[f][s]=w;
    edges[s][f]=w;
}
prismalgo(edges,n);
return 0;
}