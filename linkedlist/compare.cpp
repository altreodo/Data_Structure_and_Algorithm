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
bool check(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
        return true;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
        if (head1 == NULL && head2 == NULL)
            return true;
    }
    return false;
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
    int m;
    cin >> m;
    for (int y = 0; y < m; y++)
    {
        int k;
        cin >> k;
        if (head2 == NULL)
        {
            Node *nd = new Node(k);
            head2 = nd;
            tail2 = nd;
        }
        else
        {
            Node *nd = new Node(k);
            tail2->next = nd;
            tail2 = tail2->next;
        }
    }
    cout << check(head1, head2);
}