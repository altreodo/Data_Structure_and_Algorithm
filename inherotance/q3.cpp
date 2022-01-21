#include<iostream>
#include<string>
using namespace std;
class first{
    public:
    void half(int i){
        for(int x=1;x<=i;x++){
            for(int y=1;y<=x;y++){
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }
};
class second{
    public:
    void floyd(int i){
        for(int x=1;x<=i;x++){
            for(int y=1;y<=x;y++){
                cout<<"*"<<" ";
            }
            cout<<endl;
        }
    }
};
class done:public first,public second{
};
int main(){
    int i;
    cin>>i;
    done obj;
    obj.half(i);
    obj.floyd(i);
}