#include<bits/stdc++.h>
using namespace std;
bool issafe(int**ar,int i,int j){
    if(ar[i][j]==0){
        return false;
    }
    return true;
}
bool backtr(int**ar,vector<vector<int>>&v,int i,int j){
    if(i>=v.size()|| j>=v[0].size()){
        return false;
    }if(i==v.size()-1 && j==v[0].size()-1 && ar[i][j]==1){
        v[i][j]=1;
        return true;
    }
    if(issafe(ar,i,j)){
        v[i][j]=1;
        if(backtr(ar,v,i+1,j)){
            return true;
        }
        if(backtr(ar,v,i,j+1)){
            return true;
        }
        v[i][j]=0;
    }
    return false;
}
int main(){
int n,m;
cin>>n>>m;
int **ar=new int*[n];
for(int y=0;y<n;y++){
ar[y]=new int[m];
for(int u=0;u<m;u++){
cin>>ar[y][u];
}
}
vector<vector<int>>v;
v.resize(n,vector<int>(m,0));
if(backtr(ar,v,0,0)){
    cout<<"Path of rat"<<endl;
for(int y=0;y<n;y++){
for(int u=0;u<m;u++){
cout<<v[y][u]<<" ";
}
cout<<endl;
}
}else{
    cout<<"Rat cant reach his position"<<endl;
}
return 0;
}