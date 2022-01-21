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
bool check(BST<int>*root,int mx,int mn){
    if(root==NULL){
        return true;
    }
    if(root->data>mx){
        return false;
    }
    if(root->data<mn){
        return false;
    }
    if(check(root->left,root->data-1,mn) && check(root->right,mx,root->data)){
        return true;
    }
    return false;
}
int main(){
BST<int>*root=takeinput();
if(check(root,INT_MAX,INT_MIN)){
    cout<<"true";
}else{
    cout<<"false";
}
return 0;
}