//print all possible sentence by given word in string
#include<iostream>
#include<string>
 using namespace std;
 int main(){
     int o=0,n=3,m=3;
     string l;
    string s[n][m]={{"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}};
    for(int i=0;i<=n-1;i++){
            for(int k=0;k<=m-1;k++){ 
                cout<<s[0][i];
                while(o<=n-1){
                    cout<<s[o][k]<<' ';
                    o++;
            }
            o=0;
            cout<<endl;
        }
    }
 }