#include<iostream>
#include<string>
using namespace std;
class first{
    public:
    void op(string s1,string s2){
        for(int i=0;i<s2.length();i++){
            for(int x=0;x<s1.length();x++){
                if(s1[x]==s2[i]){
                    s1=s1.erase(x,1);
                    x=x-1;
                }
            }
        }
    cout<<s1<<endl<<s2;
    }
};
class second:public first{
};
int main(){
 string s1,s2;
 getline(cin,s1);
 getline(cin,s2);
 second obj;
 obj.op(s1,s2);
}