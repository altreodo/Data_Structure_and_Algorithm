#include<bits/stdc++.h>
using namespace std;
int mincount(string s,string t){
    if(s.length()==0 || t.length()==0){
        return max(s.length(),t.length());
    }
    if(s[0]==t[0]){
        return mincount(s.erase(0,1),t.erase(0,1));
    }
    string k=to_string(s[0]);
    return 1+min(min(mincount(s.erase(0,1),t),mincount(s,t.erase(0,1))),mincount(s.erase(0,1),t.erase(0,1)));
}
int main(){
string s,t;
cin>>s>>t;
cout<<mincount(s,t);
return 0;
}