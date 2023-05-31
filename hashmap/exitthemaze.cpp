#include <iostream>
#include <vector>
using namespace std;
void ways(long long int ar[6][6],long long int a,long long int b,vector<long long int>&arr){
   if(a>=6 || b>=6 || ar[a][b]==1){
      return;
    }
    if(a==5 & b==5){
    arr.push_back(1);
    }
    ways(ar,a+1,b,arr);
    ways(ar,a,b+1,arr);
   // ways(ro,col,a-1,b,c,d,arr);
  // ways(ro,col,a,b-1,c,d,arr);
}
int main(){
    long long int ar[6][6],mn=0;
    vector<long long int>arr;
    for(int y=0;y<6;y++){
        for(int u=0;u<6;u++){
            cin>>ar[y][u];
        }
    }
    ways(ar,0,0,arr);
    for( long long int i=0;i<arr.size();i++){
        if(arr[i]==1){
          cout<<"YES";
          mn++;
          break;
        }
    }
    if(mn==0){
        cout<<"NO";
    }
    return 0;
}