#include<bits/stdc++.h>
using namespace std;
bool maek(int ** edges,int k,int sv,bool * visited,int num2){
    queue<int>q;
    q.push(sv);
    while(!q.empty()){
    int op=q.front();
    q.pop();
    if(!visited[op]){
    //cout<<op<<" ";
    visited[op]=true;
    if(visited[num2]){
        return true;
    }
    for(int i=0;i<k;i++){
        if(edges[op][i]==1){
            q.push(i);
        }
    }
    }
    }
    return false;
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
cout<<"Enter the node for which path to be checked ";
int num1,num2;
cin>>num1>>num2;
bool * visited=new bool[n];
for(int y=0;y<e;y++){
    visited[y]=false;
}
if(maek(edges,n,num1,visited,num2)){
    cout<<"Yes there is path between "<<num1<<" "<<num2;
}else{
    cout<<"NO, there is no path between "<<num1<<" "<<num2;
}
return 0;
}