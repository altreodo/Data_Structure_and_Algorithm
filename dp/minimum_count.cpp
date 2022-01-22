#include<bits/stdc++.h>
using namespace std;
int dp[10000]={0};
int mincount(int n,int i,int ml) {
    if(pow(i,2)>ml){
        return 99999;
    }
	if(n==0){
        return 0;
    }
    if(n<0){
        return 99999;
    }
    if(dp[n]!=0){
    return dp[n];
    }
    dp[n]=min(1+mincount(n-pow(i,2),i,ml),mincount(n,i+1,ml));
    return dp[n];
}
int main(){
int n;
cin>>n;
cout<<mincount(n,1,n);
return 0;
}