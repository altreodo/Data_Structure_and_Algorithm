#include <iostream>
using namespace std;

int main()
{
    string s;
    int k=0;
    cin>>s;
    int mx=-1;
     for(int i=0;i<s.length();i++){
        if(s[i]==s[i+1]){
             k++;
        }else{
            k=0;
            }
                mx=max(k+1,mx);
        }
        cout<<mx;
        return 0;
}