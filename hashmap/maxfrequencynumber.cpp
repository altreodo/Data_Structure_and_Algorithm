#include<bits/stdc++.h>
using namespace std;

int main(){
int n,p=0,ans;
cin>>n;
int ar[n];
unordered_map<int,int>op;
for(int y=0;y<n;y++){
    cin>>ar[y];
    op[ar[y]]++;
    if(op[ar[y]]>p){
        p=op[ar[y]];
        ans=ar[y];
    }
}
cout<<ans;
return 0;
}