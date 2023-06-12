#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node*prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev=NULL;
    }
};
Node* reverse(Node *head1)
{    int o=0;
    Node* a=head1;
    Node* b=head1->next;
    while(a!=NULL){
        Node* op=a->next;
        a->next=a->prev;
        a->prev=op;
        if(a->prev==NULL)return a;
        a=a->prev;
    }
    return NULL;
}
int main()
{
    int n;
    cin >> n;
    Node *head1 = NULL;
    Node *tail = NULL;
    Node *pre = NULL;
    for (int y = 0; y < n; y++)
    {
        int k;
        cin >> k;
        if (head1 == NULL)
        {
            Node *nd = new Node(k);
            head1 = nd;
            tail=nd;
            nd->prev=NULL;
            pre=nd;
        }
        else
        {
            Node *nd = new Node(k);
            tail->next = nd;
            nd->prev=pre;
            pre=nd;
            tail = tail->next;
        }
    }
//      Node* head=head1;
//     while(head!=NULL){
//     cout<<head->data<<" ";
//     head=head->next;
//    }
   Node* headp=reverse(head1);

   while(headp!=NULL){
    cout<<headp->data<<" ";
    headp=headp->next;
   }

}