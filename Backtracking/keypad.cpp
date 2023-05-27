#include <bits/stdc++.h>
using namespace std;
void str(string s,string m){
    if(s.length()==0){
        return;
    }
for(int l=0;l<m.length();l++){
    
    cout<<s[0]<<m[l]<<endl;
}
str(s.erase(0,1),m);
}
int main(){
    vector<string> keypad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int i,j;
    cin>>i>>j;
    string s=keypad[1],p=keypad[0];
    str(s,p);

}


