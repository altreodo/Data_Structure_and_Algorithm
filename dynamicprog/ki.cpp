#include<iostream>
using namespace std;


int main (){

  int c;
  cin>>c;
  while(c>0){
      for(int r=1;r<=c;r++){
          cout<<"*";
       }
       cout<<endl;
       c=c-1;
    }
    return 0;
}