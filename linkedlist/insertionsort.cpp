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
Node* insertionsort(Node *head1)
{    int o=0;
    Node* a=head1;
    Node* b=head1->next;
    while(a!=NULL){
        b=a->next;
        while(b!=NULL){
         if(a->data>b->data){
           int temp=a->data;
            a->data=b->data;
            b->data=temp;
         }
         b=b->next;
        }
        if(o==0){
            o=1;
            head1=a;
        }
        Node* head=head1;
         while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
   }
   cout<<'\n';
        a=a->next;
    }
    return head1;
}
int main()
{
    int n;
    cin >> n;
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
   Node* head=insertionsort(head1);

   while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
   }

}