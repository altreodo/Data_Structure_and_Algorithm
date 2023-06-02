#include<iostream>
#include<string>
 using namespace std;
 class sumnum{
     public:
     int num1,num2;
     sumnum (){
     cin>>num1>>num2;
     }
     void show(){
         cout<<"sum of"<<num1<<" and "<<num2<<" = "<<num1+num2;
     }
};
int main(){
    sumnum obj;
    obj.show();
    return 0;
}