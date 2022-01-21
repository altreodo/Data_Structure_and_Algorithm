#include<iostream>
using namespace std;
bool dp_sub(int ar[],int n,int k){
    if(n==0 & k!=0){
        return false;
    }
if(k==0){
    return true;
}else if(k>0){
    return (dp_sub(ar,n-1,k-ar[n-1])||dp_sub(ar,n-1,k));
}
}
int main(){
int n,k;
cin>>n>>k;
int ar[n];
for(int m=0;m<n;m++)cin>>ar[m];
if(dp_sub(ar,n,k)){
    cout<<"YES"<<endl;
}else{
    cout<<"NO"<<endl;
}
return 0;
}