#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insert(node* &head,int k){
    
    node* n=new node(k);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
temp=temp->next;
    }
    temp->next=n;
}
void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void del(node* &l,int val){
    node* temp=l;
    
    while(temp->next->data!= val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
    }
int main(){
    node* head=NULL;
    for(int y=0;y<6;y++){
        int l;
        cin>>l;
     insert(head,l);
    }
    display(head);
    del(head,4);
    display(head);
}