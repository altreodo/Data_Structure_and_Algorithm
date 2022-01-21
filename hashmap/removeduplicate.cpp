#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
int ar[n];
unordered_map<int,int>op;
for(int y=0;y<n;y++){
    cin>>ar[y];
    op[ar[y]]++;
}
unordered_map<int,int>::iterator it=op.begin();
while(it!=op.end()){
    cout<<(*it).first<<" ";
    it++;
}
return 0;
}