#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
void dialpad(map<int,string>&m,string input,int i,string s){
    if(i>=input.size()){
        ans.push_back(s);
        return;
    }
    for(int y=0;y<m[input[i]-'0'].length();y++){
    s+=(m[input[i]-'0'][y]);
    dialpad(m,input,i+1,s);
    s.erase(s.length()-1,1);
    }
    
}
int main(){
    string input;
    cin>>input;
    map<int,string>m;
    m[2]="ABC";
    m[3]="DEF";
    m[4]="GHI";
    m[5]="JKL";
    m[6]="MNO";
    m[7]="PQRS";
    m[8]="TUV";
    m[9]="WXYZ";
    dialpad(m,input,0,"");
    cout<<"All possible string :\n";
    for(auto it:ans){
        cout<<(it)<<" ";
    }
    cout<<"Total combination :"<<ans.size();
}