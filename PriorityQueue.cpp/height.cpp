#include<iostream>
using namespace std;


int main(){
    int n,mx=9999;
    cin>>n;
    int a[n-1],b[n-2];
    for (int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n-2;i++){
        b[i]=a[i+1]-a[i];
    }
    for (int i=0;i<=n-2;i++){
        mx=min(b[i],mx);
    }
    cout<<mx;

}