#include<bits/stdc++.h>
using namespace std;
int result=0;
int getter(int a,int b,int i){
    int total=a;
    a=a-pow(i,b);
    if(a==0){
        return 1;
    }
    if(a<0){
        return 0 ;
    }
    return getter(a,b,i+1)+getter(total,b,i+1);
}




int main(){
int a,b;
cin>>a>>b;
cout<<getter(a,b,1);
//result;
return 0;
}