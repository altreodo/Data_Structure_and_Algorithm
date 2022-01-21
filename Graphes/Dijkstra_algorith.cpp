#include<bits/stdc++.h>
using namespace std;



int main(){
int n,e;
cin>>n>>e;
 int **edges=new int*[n];
 int *pathlnt=new int[n];
    for(int y=0;y<n;y++){
      pathlnt[y]=INT_MAX;
   }
for(int i=0;i<n;i++){
   edges[i]=new int[n];
   for(int y=0;y<n;y++){
       edges[i][y]=0;
   }
}
for ( int i = 0; i < e; i++)
{
    int f,e,d;
    cin>>f>>e>>d;
    edges[f][e]=d;
    edges[e][f]=d;
}
bool *visited=new bool[n];
for(int i=0;i<n;i++){
    visited[i]=false;
}
pathlnt[0]=0;
queue<int>q;
q.push(0);
while(!q.empty()){
    int i=q.front();
    q.pop();
   for(int y=0;y<n;y++){
       if(edges[i][y]!=0 ){
           if(!visited[y]){
           q.push(y);
           }
           pathlnt[y]=min(pathlnt[y],edges[i][y]+pathlnt[i]);
       }
   }
   visited[i]=true;
}
cout<<"Path from 0 to "<<endl;
for(int i=0;i<n;i++){
cout<<i<<" -> "<<pathlnt[i]<<endl;
}
return 0;
}