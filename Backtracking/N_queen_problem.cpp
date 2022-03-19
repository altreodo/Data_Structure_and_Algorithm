#include<bits/stdc++.h>
using namespace std;
bool issafe(vector<vector<int>>v,int i,int j){
    int a=i;
    int b=j;
    while(a--){
        if(v[a][j]==1){
            return false;
        }
    }
    a=i;
    while(a<v.size()){
        if(v[a][j]==1){
            return false;
        }
        a++;
    }
    while(b--){
        if(v[i][b]==1){
            return false;
        }
    }
    b=j;
    while(b<v.size()){
        if(v[i][b]==1){
            return false;
        }
        b++;
    }
    a=i;
    b=j;
    int x=i,y=j;

    while(x-- && y--){
        if(v[x][y]==1){
            return false;
        }
    }while(a<v.size() && b<v.size()){
        if(v[a][b]==1){
            return false;
        }
        a++;
        b++;
    }
    a=i;
    b=j;
    while(a>=0 && b<v.size()){
        if(v[a][b]==1){
            return false;
        }
        a--;
        b++;
    }
    a=i;
    b=j;
    while(b>=0 && a<v.size()){
        if(v[a][b]==1){
            return false;
        }
        a++;
        b--;
    }
    return true;
}
void print(vector<vector<int>>v){
    cout<<"Genrated output is ------->"<<endl;
for(int y=0;y<v.size();y++){
    for(int u=0;u<v.size();u++){
        cout<<v[y][u]<<" ";
}
cout<<endl;
}
}
vector<vector<int>>ans;
void nqueen(vector<vector<int>>v,int n,int i,int j){
    if(n==0){
        ans.resize(v.size(),vector<int>(n,0));
        ans=v;
        return;
    }
    if(i>=v.size()){
        return;
    }
        for(int u=0;u<v.size();u++){
            if(issafe(v,i,u)){
                v[i][u]=1;
                nqueen(v,n-1,i+1,u);
                v[i][u]=0;
            }
    }
    return;

}
int main(){
int n;
cin>>n;
vector<vector<int>>v;
v.resize(n,vector<int>(n,0));
nqueen(v,n,0,0);
print(ans);
return 0;
}