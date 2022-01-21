#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int data){
    data=data;
    next=NULL;
}
};
Node *input(){
    Node* head=NULL;
    Node* tail=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
int length(Node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
int main(){
long long q;
cin>>q;
while(q--){
    Node *pt=input();
    cout<<length(pt)<<endl;
}
return 0;
}