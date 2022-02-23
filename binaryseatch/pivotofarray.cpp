#include<bits/stdc++.h>
using namespace std;
int pivot(int ar[],int n){
    int left=0,right=n-1;
    while(left<right){
        int mid=right-((right-left)/2);
        if(ar[mid]>ar[mid-1] && ar[mid+1]){
            return mid;
        }
        if(ar[mid]>ar[right]){
            left=mid;
        }
        else{
            right=mid;
        }
    }
    return -1;
}
int main(){
int n;
cin>>n;
int ar[n];
for(int y=0;y<n;y++){
    cin>>ar[y];
}
cout<<pivot(ar,n);
return 0;
}