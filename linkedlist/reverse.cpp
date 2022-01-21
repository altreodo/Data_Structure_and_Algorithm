#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int data){
    this->data=data;
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
void print(Node* head){
    if(head->next==NULL){
        cout<<head->data<<" ";
        return;
    }
    print(head->next);
    cout<<head->data<<" ";
}
int main(){
long long q;
cin>>q;
while(q--){
    Node *pt=input();
    print(pt);
}
return 0;
}