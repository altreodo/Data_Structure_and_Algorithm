#include<bits/stdc++.h>
using namespace std;
string reove(char s[]){
    if(s[0]=='\0'){
        string op=s;
        return op;
    }
    if(s[0]=='x'){
        return reove(s+1);
    }
    return s[0]+reove(s+1);
}
int main(){
char s[10000];
cin>>s;
cout<<reove(s);
return 0;
}