#include<bits/stdc++.h>
using namespace std;
void klargest(int ar[],int n,int k){
    //int mn;
priority_queue<int,vector<int>,greater<int>>q;
for(int y=0;y<k;y++){
    q.push(ar[y]);
}
for(int y=k;y<n;y++){
q.push(ar[y]);
q.pop();
}

cout<< q.top();
}
int main(){
int n,k;
cin>>n;
int ar[n];
for(int y=0;y<n;y++){
cin>>ar[y];
}
cin>>k;
klargest(ar,n,k);
return 0;
}
//Time complexicity O(nlogk)
//Space complexity O(n)