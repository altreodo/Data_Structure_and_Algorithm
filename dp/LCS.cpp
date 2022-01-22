#include<bits/stdc++.h>
using namespace std;
int minsubsequence(string s,string t,int **dp){
    if(s.length()==0 || t.length()==0){
        return 0;
    }
    if(s[0]==t[0]){ 
        dp[t.length()][s.length()]=1+minsubsequence(s.erase(0,1),t.erase(0,1),dp);
        return dp[t.length()][s.length()];
    }
    if(dp[t.length()][s.length()]!=-1){
        return dp[t.length()][s.length()];
    }
    dp[t.length()][s.length()]= max(minsubsequence(s.erase(0,1),t,dp),minsubsequence(s,t.erase(0,1),dp));
    return dp[t.length()][s.length()];
}
int main(){
string s,t;
cin>>s>>t;
int ** dp=new int*[10000];
for(int i=0;i<10000;i++){
    dp[i]=new int[10000];
}
for(int i=0;i<10000;i++){
    for(int y=0;y<10000;y++){
        dp[i][y]=-1;
    }
}
cout<<minsubsequence(s,t,dp);
return 0;
}