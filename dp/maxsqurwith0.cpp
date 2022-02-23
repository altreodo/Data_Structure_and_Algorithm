#include<bits/stdc++.h>
using namespace std;

int get(int**ar,int**ans,int n,int m,int i,int j){
    if(i==n || j==m){
        return 0;
    }
    if(ar[i][j]==1){
        ans[i][j]=0;
    }else{
        ans[i][j]=1+min(min(ans[i-1][j],ans[i][j-1]),ans[i-1][j-1]);
    }
    return max(ans[i][j],max(get(ar,ans,n,m,i+1,j),get(ar,ans,n,m,i,j+1)));
}

int main(){
int n,m,mx=0;
cin>>n>>m;

int ** ar=new int*[n];
int **ans=new int*[n];
for(int y=0;y<n;y++){
    ar[y]=new int[m];
    ans[y]=new int[m];
    for(int i=0;i<m;i++){
        cin>>ar[y][i];
        ans[y][i]=0;
    }
}
for(int y=0;y<n;y++){
    if(ar[0][y]==0){
        ans[0][y]=1;
        mx=1;
    }
    if(ar[y][0]==0){
        ans[y][0]=1;
        mx=1;
    }
}
cout<<max(mx,get(ar,ans,n,m,1,1));
return 0;
}