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
    Node* heade=NULL;
    Node* taile=NULL;
     Node* heado=NULL;
    Node* tailo=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        Node* newnode=new Node(data);
        if(data%2==0){
            if(heade==NULL){
            heade=newnode;
            taile=newnode;
            }else{
                taile->next=newnode;
                taile=taile->next;
            }
        }else{
            if(heado==NULL){
            heado=newnode;
            tailo=newnode;
            }else{
                tailo->next=newnode;
                tailo=tailo->next;
            }
        }
        cin>>data;
    }
    Node* rt=heado;
    if(heado!=NULL){
        tailo->next=heade;
    }else{
        rt=heade;
    }
    return rt;
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
    print(pt);
}
return 0;
}