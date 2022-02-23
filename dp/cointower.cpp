#include<bits/stdc++.h>
using namespace std;
bool winner(int k,int x,int y,bool j){
    if(k-x==0 || k-y==0 || k-1==0){
        return j;
    }
    if(k<0){
        return !j;
    }
    if(winner(k-x,x,y,!j)|| winner(k-1,x,y,!j) || winner(k-y,x,y,!j)){
        return j;
    }
    return !j;
}
int main(){
int k,x,y;
cin>>k>>x>>y;
if(winner(k,x,y,true)){
    cout<<"Beerus";
}else{
    cout<<"Whis";
}
return 0;
}