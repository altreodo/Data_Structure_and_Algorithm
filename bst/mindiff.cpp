#include <iostream>

using namespace std;

int main() {
    long long t,k,res;
    cin>>t>>k;
    long long ar[t];
    for(int y=0;y<t;y++){
        cin>>ar[y];
    }
    int front=0;
    int end=t-1;
    while(front<=end){
        int mid=front-((front-end)/2);
        if(ar[mid]==k){
            res=ar[mid];
            break;
        }else if(k>ar[mid] & k<ar[mid+1]){
            int l=min(abs(ar[mid]-k),abs(ar[mid+1]-k));
            if(l==abs(ar[mid]-k)){
                res=ar[mid];
            }else{
                res=ar[mid+1];
            }
            break;
        }else if(k>ar[mid]){
            front=mid+1;
        }else{
            end=mid-1;
        }
    }
    cout<<res<<endl;
}