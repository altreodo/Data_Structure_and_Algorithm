#include<bits/stdc++.h>
using namespace std;
void backt(int **ar,int n,int m,int i,int j){
    if(i==n-1 && j==m-1 ){
        return ;
    }
    if(i>=n || j>=m){
        return;
    }
    if(ar[i][j]==0 ){
     return ;
    }
    if(i<n-1 & j<m-1 ){
        if(ar[i+1][j]==0 && ar[i][j+1]==0){
            ar[i][j]=0;
            return;
        }
    }
    if(i==n-1 && ar[i][j+1]==0){
    ar[i][j]=0;
    return ;
    }
    if(j==m-1 && ar[i+1][j]==0){
    ar[i][j]=0;
    return ;
    }
    backt(ar,n,m,i+1,j);
    backt(ar,n,m,i,j+1);
}
int main(){
int n, m;
cin>>n>>m;
int **ar=new int*[n];
for(int y=0;y<n;y++){
    ar[y]=new int[m];
    for(int x=0;x<m;x++){
        cin>>ar[y][x];
    }
}
backt(ar,n,m,0,0);
cout<<"ans"<<endl;
for(int y=0;y<n;y++){
    //ar[y]=new int[m];
    for(int x=0;x<m;x++){
        cout<<ar[y][x]<<" ";
    }
    cout<<endl;
}
return 0;
}