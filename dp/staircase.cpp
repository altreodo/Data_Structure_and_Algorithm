#include<bits/stdc++.h>
using namespace std;
int dp[10000]={0};
int countStepsToOne(int n) {
	if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int k=0,m=0,l=0;
    if(dp[n]!=0){
    return dp[n];
    }
    k=countStepsToOne(n-2);
    l=countStepsToOne(n-1);
    m=countStepsToOne(n-3);
    dp[n]=k+m+l;
    return dp[n];
}
int main(){
int n;
cin>>n;
cout<<countStepsToOne(n);
return 0;
}