#include<iostream>
using namespace std;
void TOH(int n,char s,char au,char d){
    if(n==0){
        return;
    }
TOH(n-1,s,d,au);
cout<<s<<" "<<d<<endl;
TOH(n-1,au,s,d);
}
int main(){
char s='a',d='c',au='b';
int n;
cin>>n;
TOH(n,s,au,d);
return 0;
}