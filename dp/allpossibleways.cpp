#include<bits/stdc++.h>
using namespace std;
int getter(int a,int b,int i,int ap){
    if(pow(i,b)==a){
        return 1;
    }
    if(pow(i,b)>a){
        return 0;
    }
    return getter(a-pow(i,b),b,i+1,ap)+getter(a,b,i+1,ap);
}
int main(){
int a,b;
cin>>a>>b;
cout<<getter(a,b,1,a);
return 0;
}