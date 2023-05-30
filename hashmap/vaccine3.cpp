#include <iostream>

using namespace std;

int main() {
    int x;
    cin>>x;
    while(x--){
        long long v,p,sum=0;
        cin>>v>>p;
        int arr[10];
        for(int i=0;i<10;i++){
            cin>>arr[i];
        }for(int i=v-1;i<10;i++){
            sum+=arr[i];
        }
        long long m=sum/p;
        if ( p>arr[v-1]){
            if((sum-arr[v-1])%p==0){
            cout<<((sum-arr[v-1])/p)+1<<" "<<((sum-arr[v-1])/p)+1<<endl;
            }else{
                cout<<((sum-arr[v-1])/p)+1<<" "<<(sum/p)+1<<endl;
            }
        }else if ( p<arr[v-1]){
            if(sum%p!=0){
                m=m+1;
            }
            cout<<((sum-arr[v-1])/p)+1<<" "<<m<<endl;
        }
        else if(sum%p==0){
            cout<<m<<" "<<m<<endl;
        }else{
            cout<<m<<" "<<m+1<<endl;
        }
    }

}