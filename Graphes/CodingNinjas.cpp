#include<iostream>
using namespace std;
int main(){
int r,c;
cin>>r>>c;
char ar[r][c];
int **edges=new int*[r];
for(int y=0;y<r;y++){
 edges[y]=new int[c];
 for(int i=0;i<c;i++){
     edges[y][i]=0;
 }
}
for(int i=0;i<r;i++){
    string s;
    cin>>s;
    for(int y=0;y<c;y++){
    ar[i][y]=s[y];
    }
}
for(int i=0;i<r-1;i++){
    for(int y=0;y<c-1;y++){
    edges[i][y+1]=1;
    edges[y+1][i]=1;
    }
}
return 0;
}