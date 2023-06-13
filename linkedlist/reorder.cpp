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
Node* reorder(Node *head1)
{  
    //cout<<head1->data;
      int o=0;
Node* po=head1;
int n=0;
while(po!=NULL){
    n++;
    po=po->next;
}
    Node* a=head1;
    Node* b=head1->next;
    // while(a!=NULL){
    //     b=a->next;
    //     int i=0;
    //    Node* op=a;
    //    while(i<n){
    //    op=op->next;
    //    i++;
    //    }
    //    n-=2;
    //    a->next=op;
    //    op->next=b;
    //    a=b;
    // }
    return head1;
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
        }
        else
        {
            Node *nd = new Node(k);
            tail->next = nd;
            tail = tail->next;
        }
    }
    while(head1!=NULL){
    cout<<head1->data<<" ";
    head1=head1->next;
   }
   Node* headp=reorder(head1);

   while(headp!=NULL){
    cout<<headp->data<<" ";
    headp=headp->next;
   }

}