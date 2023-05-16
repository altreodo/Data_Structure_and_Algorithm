#include<bits/stdc++.h>
using namespace std;
bool issafe(vector<vector<int>>&v,int x,int y,int i){
    int a=x%3,b=y%3;
    if(a==1){
        x--;
    }else if(a==2){
        x-=2;
    }
    if(b==1){
        y--;
    }else if(b==2){
        y-=2;
    }
    for(int l=x;l<x+3;l++){
        for(int p=y;p<y+3;p++){
            if(v[l][p]==i)return false;
        }
    }
    return true;
}
bool suduko(vector<vector<int>>&v,int x,int y ){
    if(y==9){
        x++;
        y=0;
    }
    if(x==9)return true;
    if(v[x][y]==-1){
        for(int u=1;u<=9;u++){
            if(issafe(v,x,y,u)){
                v[x][y]=u;
                if(suduko(v,x,y+1)){
                    return true;
                }
                v[x][y]=-1;
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>>v(9,vector<int>(9));
    for(int y=0;y<9;y++){
        for(int u=0;u<9;u++){
            cin>>v[y][u];
        }
    }
    if(suduko(v,0,0)){
    for(int y=0;y<9;y++){
        for(int u=0;u<9;u++){
            cout<<v[y][u]<<" ";
        }
        cout<<'\n';
    }
    }
}