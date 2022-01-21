#include<bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode*>children;
    TreeNode(T data){
        this->data=data;
    }
};
TreeNode<int>* takeinput(){
 int rootdata;
 cin>>rootdata;
 TreeNode<int>*root=new TreeNode<int>(rootdata);
 queue<TreeNode<int>*>pending;
 pending.push(root);
 while(pending.size()!=0){
       TreeNode<int>*front=pending.front();
       cout<<"Enter the number of elment in"<<front->data<<endl;
       pending.pop();
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
       cout<<i<<"-element of "<<front->data;
       int child;
       cin>>child;
       TreeNode<int>*ele=new TreeNode<int>(child);
       front->children.push_back(ele);
    pending.push(ele);
   }
 }
 return root;
}
int maxsum(TreeNode<int>*root,int sum,int* op){
    if(root->children.size()==0){
        return 0;
    }
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    for(int i=0;i<root->children.size();i++){
        if(sum<maxsum(root->children[i],root->data,op)){
            sum=maxsum(root->children[i],root->data,op);
            (*op)=root->data;
        }
    }
    return *op;
}
int main(){
TreeNode<int>* root=takeinput();
int u;
cout<<maxsum(root,root->data,&u);
return 0;
}