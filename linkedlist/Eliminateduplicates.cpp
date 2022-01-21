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
void dub(Node*head){
    while(head->next!=NULL){
        if(head->data==head->next->data){
            head->next=head->next->next;
        }else{
            head=head->next;
        }
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
    Node *pt=input();
    dub(pt);
    print(pt);
}
return 0;
}