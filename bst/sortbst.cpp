#include<bits/stdc++.h>
using namespace std;
void bubblesort(int *ar, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ar[j] > ar[j+1]){
                swap(ar[j], ar[j+1]);
            }
        }
    }
}
void bst(int ar[],int k){
    int front=0;
    int end=8;
    while(front<=end){
        int mid=front-((front-end)/2);
        if(ar[mid]==k  ){
            cout<<mid<<endl;
            return;
        }
        else if(ar[front]<ar[mid]){
            front=mid+1;
        }else if(ar[end]>ar[mid]){
            end=mid-1;
        }
    }
    cout<<-1<<endl;
}
int main(){
    int k=50;
int ar[]={2,20,1,33,90,1,50,10,100};
sort(ar,ar+9);
bst(ar,k);
return 0;
}