#include<bits/stdc++.h>
using namespace std;
bool check(string s){
    stack<char>v;
for(int y=0;y<s.length();y++){
    if(s[y]=='('){
        v.push(s[y]);
    }else{
        if(v.size()==0){
            return false;
        }else{
            v.pop();
        }
    }
}
if(v.size()==0){
    return true;
}else{
    return false;
}
}
int main(){
string s;
cin>>s;
stack<char>v;
if(check(s)){
    cout<<"true"<<endl;
}else{
    cout<<"false"<<endl;
}
return 0;
}