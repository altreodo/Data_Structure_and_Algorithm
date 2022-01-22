#include<bits/stdc++.h>
using namespace std;
int mincost(int **ar,int i,int j,int ** dp){
    if(i==0 && j==0){
        dp[i][j]=ar[i][j];
    return ar[i][j];
    }
if(i<0 || j<0){
    return 9999999;
}
    if(dp[i][j]!=-99999){
        return dp[i][j];
    }
dp[i][j]= ar[i][j]+min(min(mincost(ar,i-1,j,dp),mincost(ar,i,j-1,dp)),mincost(ar,i-1,j-1,dp));
return dp[i][j];
}
int minCostPath(int** cost, int n, int m, int x, int y)
{
    int **dp=new int*[1001];
    for(int y=0;y<1001;y++){
    dp[y]=new int[1001];
}
for(int i=0;i<1001;i++){
    for(int y=0;y<1001;y++){
       dp[i][y]=-99999;
    }
}
    return mincost(cost,x-1,y-1,dp);
}
int main(){
int n,m;
cin>>n>>m;
int **ar=new int*[n];
for(int i=0;i<n;i++){
    ar[i]=new int[m];
}
for(int i=0;i<n;i++){
    for(int y=0;y<m;y++){
        cin>>ar[i][y];
    }
}
int op,np;
cin>>op>>np;

int **dp=new int*[101];
for(int y=0;y<100;y++){
    dp[y]=new int[101];
}
for(int i=0;i<101;i++){
    for(int y=0;y<101;y++){
       dp[i][y]=-99999;
    }
}
cout<<minCostPath(ar,op,np,n,m);
return 0;
}