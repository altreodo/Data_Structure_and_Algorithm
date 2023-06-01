#include <iostream>
#include <string>
using namespace std;
 void fill(int **arr,int a,int b,int k){
    if(a<0 || a>=8 || b<0 || b>=8){
        return;
    }
   if(arr[a][b]==k){
         arr[a][b]=3;
    }else{
        return;
    }
    fill(arr,a+1,b,k);
    fill(arr,a,b+1,k);
    fill(arr,a-1,b,k);
    fill(arr,a,b-1,k);
    
}
int main() {
    int a,b,k;
    cin>>a>>b;
    int **arr=new int * [a];
        for(int j=0;j<b;j++){
            arr[j]=new int[b];
        }   
        for(int i=0;i<a;i++){
            for(int y=0;y<b;y++){
                cin>>arr[i][y];
            }
        }
    k=arr[a][b];
    fill(arr,a,b,k);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}