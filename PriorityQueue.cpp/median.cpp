#include<bits/stdc++.h>
using namespace std;
int main(){
priority_queue<int>mx;
priority_queue<int,vector<int>,greater<int>>mn;
int n;
cin>>n;
int ar[n];
for(int i=0;i<n;i++){
    cin>>ar[i];
}
mx.push(ar[0]);
cout<<mx.top()<<" ";
for(int i=1;i<n;i++){
    int olp=mx.top();
   // cout<<olp<<" ";
    if(ar[i]<olp){
        mx.push(ar[i]);
    }else{
        mn.push(ar[i]);
    }
   // cout<<"m";
    if((mn.size()>mx.size()+1)){
        int m=mn.top();
        mn.pop();
        mx.push(m);
    }
   // cout<<"l";
    if(mx.size()>mn.size()+1){
        int m=mx.top();
        mx.pop();
        mn.push(m);
    }
    if((mn.size()+mx.size())%2==0){
        cout<<(mn.top()+mx.top())/2<<" ";
    }else{
        if(mx.size()>mn.size()){
            cout<<mx.top()<<" ";
        }else{
            cout<<mn.top()<<" ";
        }
    }
}
return 0;
}