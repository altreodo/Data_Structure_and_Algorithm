#include <iostream>

using namespace std;

int main() {
    int x;
    cin>>x;
    int ar[x];
    for(int o=0;o<x;o++){
        cin>>ar[o];
    }
    int front=0;
    int end=x-1;
    while(front<=end){
        int mid=front-((front-end)/2);
        if(ar[mid]<=ar[(mid+x-1)%x] & ar[mid]<=ar[(mid+1)%x]  ){
            cout<<mid<<endl;
            break;
        }else if(ar[mid]>=ar[front] && ar[mid]<=ar[end]){
                cout<<front<<endl;
                break;
            }
        else if(ar[front]<=ar[mid]){
            front=mid+1;
        }else if(ar[end]>=ar[mid]){
            end=mid-1;
        }
    }
}