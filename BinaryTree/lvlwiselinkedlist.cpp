#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Binarytree{
    public:
    T data;
    Binarytree*left;
    Binarytree*right;
    Binarytree(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~Binarytree(){
        delete left;
        delete right;
    }
};
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
Binarytree<int>* takeinput(){
    queue<Binarytree<int>*>q;
    int rootdata;
    cout<<"enter the data ";
    cin>>rootdata;
    Binarytree<int>*root=new Binarytree<int>(rootdata);
    q.push(root);
    while(!q.empty()){
        Binarytree<int>*root=q.front();
        q.pop();
        int leftdata,rightdata;
        cin>>leftdata>>rightdata;
        if(leftdata!=-1){
        Binarytree<int>*left=new Binarytree<int>(leftdata);
        q.push(left);
        root->left=left;
        }else{
             root->left=NULL;
        }
        if(rightdata!=-1){
        Binarytree<int>*right=new Binarytree<int>(rightdata);
        q.push(right);
        root->right=right;
        }else{
            root->right=NULL;
        }
    }
    return root;
}
void printo(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
void printr(Node*head){
    if(head==NULL){
        return;
    }
    printr(head->next);
    cout<<head->data<<" ";
}
void lvl(Binarytree<int>*root){
    int s=0;
    queue<Binarytree<int>*>q;
    q.push(root);
    q.push(NULL);
     Node*head=NULL;
     Node*op=NULL;
    while (!q.empty())
    {
        if(q.front()==NULL){
            q.pop();
            if(q.empty()){
                break;
            }
            if(s%2==0){
            printo(head);
            s++;
            }else{
                printr(head);
                s++;
            }
            cout<<endl;
            head=NULL;
            op=NULL;
            q.push(NULL);
        }else{
        Binarytree<int>*root=q.front();
        q.pop();
         Node* newnode=new Node(root->data);
            if(head==NULL){
                head=newnode;
                op=newnode;
            }else{
                op->next=newnode;
                op=op->next;
            }
        if(root->left!=NULL){
        Binarytree<int>*left=root->left;
        q.push(left);
        }
        if(root->right!=NULL){
        Binarytree<int>*right=root->right;
        q.push(right);
        }
        }
    }
    if(s%2==0){
            printo(head);
            s++;
            }else{
                printr(head);
                s++;
    }
}
int main(){
Binarytree<int>*root=takeinput();
lvl(root);
return 0;
}