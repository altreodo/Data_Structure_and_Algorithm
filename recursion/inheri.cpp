#include<iostream>
 using namespace std;
 class sum{
     public:
         void sumout(int n,int k){
             cout<<"sum of "<<n<<" and "<<k<<"="<<n+k<<endl;
         }
 };
 class subtraction{
     public:
         void subtract(int n,int k){
             cout<<"subtraction of  "<<n<<" and "<<k<<"="<<n-k<<endl;
         }
 };
 class multiplication{
     public:
         void multiout(int n,int k){
             cout<<"multiplication of "<<n<<" and "<<k<<"="<<n*k<<endl;
         }
 };
 class division{
     public:
         void divout(int n,int k){
             cout<<"division of "<<n<<" and "<<k<<"="<<n/k<<endl;
         }
 };
 class calculator:public sum,public subtraction,public multiplication,public division{
};
int main(){
    int a,b;
    cout<<"enter the both number";
    cin>>a>>b;
    calculator obj;
    obj.sumout(a,b);
    obj.subtract(a,b);
    obj.multiout(a,b);
    obj.divout(a,b);
    return 0;
}