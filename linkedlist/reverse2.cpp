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
Node * reverse(Node* head,Node*po,Node*op){
    while(head!=NULL){
    Node *newnode=new Node(head->data);
    op=head->next;
    head->next=po;
    po=op;
    head=op;
    }
    return po;
}
void print(Node* head){
    while(head!=NULL){
cout<<head->data<<" ";
head=head->next;
    }
    cout<<endl;
}
int main(){
long long q;
cin>>q;
while(q--){
    Node *pt=input();
    Node*po=NULL;
    Node*op=NULL;
    Node*s;
    Node * start=reverse(pt,po,op);
    print(start);
}
return 0;
}