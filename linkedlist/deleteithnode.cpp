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
Node* deletenode(Node* head,int k){
    int count=0;
    if(k==0){
        head=head->next;
    }else{
        Node *u=head;
    while(count<k-1 && head!=NULL){
        count++;
        head=head->next;
    }
    if(head!=NULL){
    if(head->next==NULL){
        head=NULL;
    }else{
    head->next=head->next->next;
    }
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
    cout<<endl;
}
int main(){
long long q;
cin>>q;
while(q--){
    Node *pt=input();
    int k;
    cin>>k;
    pt=deletenode(pt,k);
    print(pt);
}
return 0;
}