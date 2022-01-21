#include<bits/stdc++.h>
using namespace std;

int main(){
priority_queue<int>q;
int n,k;
cin>>n>>k;
int ar[n];
for(int y=0;y<n;y++){
    cin>>ar[y];
}
for(int y=0;y<k;y++){
    q.push(ar[y]);
}
for(int y=0;y<n-k;y++){
    ar[y]=q.top();
    q.pop();
    q.push(ar[y+k]);
}
int op=n-k;
while(op<n){
ar[op]=q.top();
q.pop();
op++;
}
for(int y=0;y<n;y++){
    cout<<ar[y]<<" ";
}
return 0;
}