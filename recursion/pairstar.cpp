#include<iostream>
using namespace std;
string par(char s[]){
    if(s[1]=='\0'){
        string op=s;
        return op;
    }
    if(s[0]==s[1]){
        string hc="*";
        return hc+par(s+1);
    }
    return (par(s+1));
}
int main(){
char s[10000];
cin>>s;
cout<<par(s);
return 0;
}