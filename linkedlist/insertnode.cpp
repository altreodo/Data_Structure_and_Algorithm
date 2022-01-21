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
Node* insertithnode(Node* head,int k,int data){
    int count=0;
    Node* newnode=new Node(data);
    if(k==0){
        newnode->next=head;
        head=newnode;
    }else{
        Node *u=head;
    while(count<k-1 && head!=NULL){
        count++;
        head=head->next;
    }
    Node *pt;
    pt=head->next;
    if(head!=NULL && k!=0){
    head->next=newnode;
    newnode->next=pt;
    }
    head=u;
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
cout<<head->data<<" ";
head=head->next;
    }
}
int main(){
long long q;
cin>>q;
while(q--){
    Node *pt=input();
    int k,data;
    cin>>k>>data;
    pt=insertithnode(pt,k,data);
    print(pt);
}
return 0;
}