#include<iostream>
using namespace std;
int mnstep(int n){
    if(n==1){
        return 0;
    }
    if(n<1){
        return 99999;
    }
    int k,m,l=0;
    if(n%3==0){
        m=mnstep(n/3);
    }
    if(n%2==0){
         k=mnstep(n/2);
    }
    l=mnstep(n-1);
    return min(min(k+1,l+1),m+1);
}

int main(){
int n;
cin>>n;
cout<<mnstep(n);
return 0;
}