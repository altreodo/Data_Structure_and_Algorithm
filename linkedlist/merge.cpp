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
Node *input(int n){
    int cpunt=0;
    Node* head=NULL;
    Node* tail=NULL;
    while(cpunt<n){
    int data;
    cin>>data;
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=tail->next;
        }
        cpunt++;
    }
    return head;
}
Node* merge(Node* head1, Node* head2){
int s=0;
Node* op=NULL;
Node* head=NULL;
while(head1!=NULL && head2!=NULL){
    if(head1->data<head2->data && head1!=NULL){
        Node* newnode=new Node(head1->data);
        if(s==0){
            head=newnode;
            op=newnode;
            s++;
        }else{
        op->next=newnode;
            op=op->next;
        }
        head1=head1->next;
    }else{
        Node* newnode=new Node(head2->data);
        if(s==0){
            head=newnode;
            op=newnode;
            s++;
        }else{
        op->next=newnode;
            op=op->next;
        }
        head2=head2->next;
    }
}
if(head1==NULL){
    while(head2!=NULL){
     Node* nee=new Node(head2->data);
     op->next=nee;
     op=op->next;
     head2=head2->next;
     }
}else if(head2==NULL){
    while(head1!=NULL){
    Node* newnode=new Node(head1->data);
     op->next=newnode;
     op=op->next;
     head1=head1->next;
    }
}
op=NULL;
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
int q;
cin>>q;
while(q--){
    int n,o;
    cin>>n>>o;
    Node*pt=input(n);
    Node*t=input(o);
    Node* head=merge(pt,t);
    print(head);
}
return 0;
}