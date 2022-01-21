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
void duplicate(BST<int>*root){
    if(root==NULL){
        return;
    }
    BST<int>*pt=new BST<int>(root->data);
    BST<int>*op=root->left;
    root->left=pt;
    pt->left=op;
    duplicate(root->left->left);
    duplicate(root->right);
}
void print(BST<int>*root){
    queue<BST<int>*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    { 
        if(q.front()==NULL){
            q.pop();
            if(q.empty()){
                break;
            }
            cout<<endl;
            q.push(NULL);
        }else{
        BST<int>*root=q.front();
        q.pop();
        cout<<root->data<<" ";
        if(root->left!=NULL){
        BST<int>*left=root->left;
        q.push(left);
        }
        if(root->right!=NULL){
      BST<int>*right=root->right;
        q.push(right);
        }
        }
    }
    
}
int main(){
BST<int>*root=takeinput();
duplicate(root);
print(root);
return 0;
}