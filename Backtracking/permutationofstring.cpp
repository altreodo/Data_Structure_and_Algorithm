#include<bits/stdc++.h>
using namespace std;
vector<string>v;

void getter(string s,int i){
    if(i>=s.length()){
    v.push_back(s);
        return;
    }
    string m=s;
    for(int y=i;y<s.length();y++){
    swap(m[y],m[i]);
    getter(m,i+1);
    m=s;
    }
    return;
}
void solve(){
    string s;
    cin>>s;
    getter(s,0);
    for(int u=0;u<v.size();u++){
        cout<<v[u]<<endl;
    }
}
int main(){
solve();
return 0;
}