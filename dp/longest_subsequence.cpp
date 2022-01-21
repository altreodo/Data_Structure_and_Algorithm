#include<bits/stdc++.h>
using namespace std;
int get(int ar[],int n,int i,int e){
    if(e>=n){
        return 0;
    }
    int m=0;
    if(ar[i]<ar[e]){
        m=1;
    }
    return max(m+get(ar,n,i,e+1),get(ar,n,i+1,e+1));
}
int main(){
int n;
cin>>n;
int ar[n];
for(int y=0;y<n;y++){
    cin>>ar[y];
}
cout<<get(ar,n,0,1);
return 0;
}