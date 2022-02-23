#include<bits/stdc++.h>
using namespace std;
//int result=0;
int noways(int ar[],int n,int i,int sum){
    if(sum==0){
        return 1;
    }
    if(sum<0){
        return 0;
    }
    if(i==n){
        return 0;
    }
    return noways(ar,n,i,sum-ar[i])+noways(ar,n,i+1,sum);
}
int main(){
int n;
cin>>n;
int ar[n];
for(int y=0;y<n;y++){
    cin>>ar[y];
}
int k;
cin>>k;
cout<<noways(ar,n,0,k);
return 0;
}