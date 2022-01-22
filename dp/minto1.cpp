#include<iostream>
using namespace std;
int dp[10000]={0};
int countStepsToOne(int n) {
	if(n==1){
        return 0;
    }
    if(n<1){
        return 99999;
    }
    int k=99999,m=99999,l=99999;
    if(dp[n]!=0){
    return dp[n];
    }
    if(n%2==0){
         k=countStepsToOne(n/2);
    }
    l=countStepsToOne(n-1);
    if(n%3==0){
        m=countStepsToOne(n/3);
    }
    dp[n]=1+min(min(k,l),m);
    return dp[n];
}
int main(){
int n;
cin>>n;
cout<<countStepsToOne(n);
return 0;
}