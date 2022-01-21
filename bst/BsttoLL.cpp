#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BST{
    public:
    T data;
    BST*left;
    BST*right;
    BST(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BST(){
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
class datas{
    public:
    Node*head=NULL;
    Node*tail=NULL;
};
BST<int>* takeinput(){
    queue<BST<int>*>q;
    int rootdata;
    cout<<"enter the data ";
    cin>>rootdata;
    BST<int>*root=new BST<int>(rootdata);
    q.push(root);
    while(!q.empty()){
        BST<int>*root=q.front();
        q.pop();
        int leftdata,rightdata;
        cin>>leftdata>>rightdata;
        if(leftdata!=-1){
        BST<int>*left=new BST<int>(leftdata);
        q.push(left);
        root->left=left;
        }else{
             root->left=NULL;
        }
        if(rightdata!=-1){
        BST<int>*right=new BST<int>(rightdata);
        q.push(right);
        root->right=right;
        }else{
            root->right=NULL;
        }
    }
    return root;
}
datas ll(BST<int>*root){
if(root==NULL){
    datas op;
    op.head=NULL;
    op.tail=NULL;
    return op;
}
 datas leftr=ll(root->left);
 datas rightr=ll(root->right);
Node* newnode=new Node(root->data);
datas obj;
leftr.tail->next=newnode;
newnode->next=rightr.head;
obj.tail=rightr.tail;
if(leftr.head==NULL){
    obj.head=newnode;
}else{
    obj.head=leftr.head;
}
return obj;
}
void print(Node* head){
 while(head!=NULL){
     cout<<head->data<<" ";
     head=head->next;
 }
}
int main(){
BST<int>*root=takeinput();
datas ans=ll(root);
print(ans.head);
return 0;
}