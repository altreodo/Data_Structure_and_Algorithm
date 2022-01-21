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
int maximun(BST<int>*root){
    if(root==NULL){
        return -1;
    }
    return max(max(maximun(root->left),maximun(root->right)),root->data);
}
int minimum(BST<int>*root){
    if(root==NULL){
        return 9999999;
    }
    return min(min(minimum(root->left),minimum(root->right)),root->data);
}
bool check(BST<int>*root){
    if(root==NULL){
        return true;
    }if(root->left!=NULL){
    int mx=maximun(root->left);
    if(root->data<=mx){
        return false;
    }
    if(check(root->left)){
        return true;
    }else{
        return false;
    }
    }
    if(root->right!=NULL){
    int mn=minimum(root->right);
    if(root->data>mn){
        return false;
    }
    if(check(root->right)){
        return true;
    }else{
        return false;
    }
    }
 return true;
}
int main(){
BST<int>*root=takeinput();
if(check(root)){
    cout<<"true";
}else{
    cout<<"false";
}
return 0;
}