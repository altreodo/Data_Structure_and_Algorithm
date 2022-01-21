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
void lvl(Binarytree<int>*root){
    if(root==NULL){
        return;
    }
    if((root->left!=NULL && root->right==NULL)){
        cout<<root->left->data<<" ";
    }
     if((root->left==NULL && root->right!=NULL)){
        cout<<root->right->data<<" ";
    }
    lvl(root->left);
    lvl(root->right);
}
void lvl2(Binarytree<int>*root){
    if(root==NULL){
        return;
    }
     if((root->left!=NULL && root->right==NULL)){
        cout<<root->left->data<<" ";
    }
     if((root->left==NULL && root->right!=NULL)){
        cout<<root->right->data<<" ";
    }
    lvl2(root->right);
    lvl2(root->left);
}
int main(){
Binarytree<int>*root=takeinput();
lvl(root);
//lvl2(root);
return 0;
}