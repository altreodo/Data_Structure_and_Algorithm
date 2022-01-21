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
Node* get(Node*head,int l){
    while(l--){
        head=head->next;
    }
    return head;
}
Node* get2(Node*head){
    while(head->next!=NULL){
        head=head->next;
    }
    return head;
}
Node *input(int *p){
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
        (*p)++;
        cin>>data;
    }
    return head;
}
void Append(Node*head,Node*op,Node*pt){
    while(pt!=op){
        head->next=pt;
        pt=pt->next;
        head=head->next;
    }
    head->next=NULL;
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
    int count=0;
    int *p=&count;
    Node *pt=input(p);
    Node*strt=pt;
    int k;
    cin>>k;
    Node *op=pt;
    if(k>0){
     op=get(pt,count-k);
    Node*sp=get2(pt);
    Append(sp,op,pt);
    }
    print(op);
}
return 0;
}