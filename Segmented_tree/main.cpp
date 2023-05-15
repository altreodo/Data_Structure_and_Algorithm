#include<bits/stdc++.h>
using namespace std;
int seg[4*100005],ar[4*100005];
class seg_tree{
public:
void build(int ind,int l,int r ){
    if(l==r){
        seg[l]=ar[l];
        return;
    }
    int mid=r-((r-l)/2);
    build(2*ind+1,l,mid);
    build(2*ind+2,mid+1,r);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
}
int query(int ind,int low,int high,int l,int r){
    if(low>=l && high<=r){
        return seg[ind];
    }
    if(high<l || low>r)return INT_MIN;
    int mid=r-((r-l)/2);
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return max(left,right);
}
};
int main(){
int n;
cin>>n;
for(int y=0;y<n;y++)cin>>ar[y];

return 0;
}