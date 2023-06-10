#include<iostream>
 using namespace std;

 int count(int n){
     int k=8,s,m=1,count=0;
     while(k>=0){
         s=n&m;
         n=n>>1;
         if(s==m){
             count++;
         }
         k--;
     }
     return count;
 }
 int main(){
     cout<<count(53);
 }