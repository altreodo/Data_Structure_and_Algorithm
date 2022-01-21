#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Binarytree{
public:
int data;
Binarytree*left=NULL;
Binarytree*right=NULL;
Binarytree(int data){
    this->data=data;
}
};
Binarytree<int>* takeinput(){
queue<Binarytree<int>*>q;
int data;
cin>>data;
Binarytree<int>*root=new Binarytree<int>(data);
q.push(root);
while(!q.empty()){
    Binarytree<int>* head=q.front();
    q.pop();
    int leftdata,rightdata;
    cin>>leftdata>>rightdata;
    if(leftdata!=-1){
        Binarytree<int>*left=new Binarytree<int>(leftdata);
        head->left=left;
    q.push(left);
    }else{
        head->left=NULL;
    }
    if(rightdata!=-1){
        Binarytree<int>*right=new Binarytree<int>(rightdata);
    head->right=right;
    q.push(right);
    }else{
        head->right=NULL;
    }
}
return root;
}
bool check(Binarytree<int>*root,int mx,int mn){
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
int height(Binarytree<int>*root){
    if(root==NULL){
        return 0;
    }
    return max(1+height(root->left),1+height(root->right));
}
int largest_height(Binarytree<int>*root,int mx){
    if(root==NULL){
        return 0;
    }
    if(check(root,999999,-999999)){
       mx=max(mx,height(root));
    }
    mx=max(mx,largest_height(root->left,mx));
     mx=max(mx,largest_height(root->right,mx));
     return mx;
}
int main(){
    Binarytree<int>*root;
    root=takeinput();
    cout<<largest_height(root,-1);
    return 0;
}