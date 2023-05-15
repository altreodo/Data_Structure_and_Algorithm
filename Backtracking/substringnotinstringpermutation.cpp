#include<bits/stdc++.h>
using namespace std;
void getter(string a,string b,string h){
  
   if(a.length()==0 ){
       cout<<h<<" ";
       return;
   }
  // string kp=a;
    for(int y=0;y<a.length();y++){
        // if(b[0]==a[y]){
        //     b.erase(0,1);
        // }
        // cout<<a<<" ";
        string op=h;
        char mc=a[y];
        h+=a[y];
   if(h.length()>=2){
       if(h[h.length()-2]==b[0] && h[h.length()-1]==b[1])return;
   }  
    a.erase(y,1);
    getter(a,b,h);
    a.insert(y,1,mc);
    h=op;
    }
    return;
}
int main(){
string a,b;
cin>>a>>b;
getter(a,b,"");
return 0;
}