#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node* partision(Node *head1,int x)
{    
    Node* a=NULL;
    Node* m;
    Node* tail1=NULL;
    Node*b=NULL;
    Node* tail2=NULL;
    Node* head=NULL;
    while(head1!=NULL){
   if(head1->data<x){
    if(a==NULL){
        a=head1;
        if(head==NULL){
        head=a;
        }
    }else{
        a->next=head1;
        a=a->next;
    }
   }else{
    if(b==NULL){
        tail2=head1;
        b=head1;
    }else{
        
        b->next=head1;
        b=b->next;
    }
   }
   head1=head1->next;
    }
    a->next=tail2;
    b->next=NULL;
    return head;

}
int main()
{
    int n,x;
    cin >> n>>x;
    Node *head1 = NULL;
    Node *tail = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    for (int y = 0; y < n; y++)
    {
        int k;
        cin >> k;
        if (head1 == NULL)
        {
            Node *nd = new Node(k);
            head1 = nd;
            tail = nd;
        }
        else
        {
            Node *nd = new Node(k);
            tail->next = nd;
            tail = tail->next;
        }
    }
   Node* head=partision(head1,x);

   while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
   }

}