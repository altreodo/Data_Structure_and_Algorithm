#include<bits/stdc++.h>
using namespace std;
int find(int ar[],int n,int i){
    if(i>=n){
        return 0;
    }
   return max(ar[i]+find(ar,n,i+2),find(ar,n,i+1));
}
int main(){
int n,mx=-1;
cin>>n;
int ar[n];
for(int i=0;i<n;i++){
    cin>>ar[i];
}
cout<<find(ar,n,0);
//cout<<mx<<endl;
return 0;
}