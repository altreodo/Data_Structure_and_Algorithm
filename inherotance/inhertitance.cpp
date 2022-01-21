#include <iostream>
#include<math.h>
using namespace std;
class prime{
    public:
    void prie(int i){
        int o=0;
    for(int num=2;num<i;num++){
       if(i%num==0){
           o++;
           break;
       }
    }
    if(o!=0){
        cout<<"number is not prime"<<endl;
    }else{
        cout<<"number is prime"<<endl;
    }
    }
};
class armstrong:public prime{
    public:
    void arm(int i){
    int size=floor(log10(i)+1),sum=0,k=i;
    while(i>0){
      int r=i%10;
      sum+=pow(i,size);
       i=i/10;
       }
       if(sum==k){
           cout<<"Number is armstrong";
       }else
       {
        cout<<"Number is not armstrong";
       }
       }
};

int main()
{   int i;
cin>>i;
armstrong obj;
obj.prie(i);
obj.arm(i);
    return 0;
}