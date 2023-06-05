#include <iostream>
using namespace std;
int factorial(int o){
    if(o<=0){
        return 1;
    }return o*factorial(o-1);
}
int main() {
    int i;
    cin>>i;
    while(i--){
        int n;
        cin>>n;
    cout<<factorial(n)<<endl;
    }
    return 0;
}