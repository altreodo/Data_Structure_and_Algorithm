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
int o;




cin>>o;
int br[o];
for(int u=0;u<o;u++){
    cin>>br[u];
    if(op[br[u]]>0){
        cout<<br[u]<<" ";
    }
}
return 0;
}