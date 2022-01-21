#include<bits/stdc++.h>
using namespace std;
void ksmallest(int ar[],int n,int k){
    //int mn;
priority_queue<int>q;
for(int y=0;y<k;y++){
    q.push(ar[y]);
}
for(int y=k;y<n;y++){
q.push(ar[y]);
q.pop();
}
while(q.size()>0){
    cout<<q.top()<<" ";
    q.pop();
}
//return q.top();
}
int main(){
int n,k;
cin>>n;
int ar[n];
for(int y=0;y<n;y++){
cin>>ar[y];
}
cin>>k;
ksmallest(ar,n,k);
return 0;
}