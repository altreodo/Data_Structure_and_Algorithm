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
void deletn(Node* head,int m,int n){
    int a=m,b=n;
while(head!=NULL){
    while(a-- && head!=NULL){
        head=head->next;
    }
    Node* sp=head->next;
    while(b-- && head!=NULL){
        Node* op=head->next;
         sp=head->next->next;
        delete op;
    }
    head->next=sp;
    a=m;
    b=n;
}
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
    int n,m;
    Node *pt=input();
    cin>>m>>n;
    deletn(pt,m,n);
    print(pt);
}
return 0;
}