#include<bits/stdc++.h>
using namespace std;
//#define MOD 100000007
int dp[100001]={0};
int get(int i){
if(i==1){
    dp[1]=1;
    return dp[i];
}if(i==2){
    dp[2]=3;
    return dp[i];
}
if(dp[i]!=0){
    return dp[i];
}
int MOD=(int)(pow(10,7)+7);
int x=get(i-1);
int y=get(i-2);
int temp1=(int)(((long)(x)*x)%MOD);
int temp2=(int)((2*(long)(x)*y)%MOD);
dp[i]=(temp1+temp2)%MOD;
return dp[i];
}
int main(){
int n;
cin>>n;
cout<<get(n);
return 0;
}