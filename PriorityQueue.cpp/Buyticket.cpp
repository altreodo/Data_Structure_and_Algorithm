#include<bits/stdc++.h>
using namespace std;
int main(){
int n,count=0,k;
cin>>n;
priority_queue<int>q;
queue<int>qr;
int ar[n];
for(int y=0;y<n;y++){
    int h;
    cin>>h;
    ar[y]=h;
    q.push(h);
    qr.push(y);
}
cin>>k;
while(qr.front()!=k || q.top()!=ar[k]){
if(ar[qr.front()]!=q.top()){
int m=qr.front();
qr.pop();
qr.push(m);
}else{
    count++;



    
    qr.pop();
    q.pop();
}
}
cout<<count+1;
return 0;
}