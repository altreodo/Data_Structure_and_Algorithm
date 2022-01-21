#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};
int main(){
node n1(3);
node* head=&n1;
node n2(7);
n1.next=&n2;
cout<<n1.data<<" "<<n2.data;
return 0;
}