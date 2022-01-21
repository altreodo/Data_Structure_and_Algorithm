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
void print(BST<int>*root,int s,int k){
    if(root==NULL){
        return;
    }
    print(root->left,s,k);
    if(root->data>=s & root->data<=k){
        cout<<root->data<<" ";
    }
    print(root->right,s,k);
}
int main(){
BST<int>*root=takeinput();
int n,k;
cin>>n>>k;
print(root,n,k);
return 0;
}