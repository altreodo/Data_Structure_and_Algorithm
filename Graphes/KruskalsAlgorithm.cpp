#include<bits/stdc++.h>
using namespace std;
class edges{
public:
int source,destination,weight;
};
bool compare(edges e1,edges e2){
    return e1.weight<e2.weight;
}
int findparent(int v,int parent[]){
    if(parent[v]==v){
        return v;
    }
    return findparent(parent[v],parent);
}
int main(){
int n,e;
cin>>n>>e;
edges * v=new edges[e];
edges* out=new edges[n-1];
for(int y=0;y<e;y++){
    int l,s,w;
    cin>>l>>s>>w;
    v[y].source=l;
    v[y].destination=s;
    v[y].weight=w;
}
sort(v,v+n,compare);
int parent[n];
for(int y=0;y<n;y++){
    parent[y]=y;
}
int count=0,op=0;
while(count<n-1){
    edges obj=v[op];
    op++;
    int v1=findparent(obj.source,parent);
    int v2=findparent(obj.destination,parent);
    if(parent[v1]!=parent[v2]){
    out[count]=obj;
    parent[v1]=v2;
    count++;
    }
}
cout<<"MST is->>>>>>"<<endl;
for(int y=0;y<n-1;y++){
    cout<<out[y].source<<" "<<out[y].destination<<" "<<out[y].weight<<endl;
}
return 0;
}