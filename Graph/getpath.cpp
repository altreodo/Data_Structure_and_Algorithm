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
int i=num1;
vector<int>v;
bool * visited=new bool[n];
for(int y=0;y<e;y++){
    visited[y]=false;
}
while(i!=num2){
if(maek(edges,n,i,visited,num2)){
    v.push_back(i);
}
visited[i]=true;
for(int y=i+1;y<n;y++){
    if(visited[y]==true){
        i=y;
        break;
    }
}for(int y=i+1;y<n;y++){
    visited[y]=false;
}
}
v.push_back(num2);
for(int u=0;u<v.size();u++){
   cout<<(v[u]);
}
return 0;
}