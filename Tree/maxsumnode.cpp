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
int maxsum(TreeNode<int>*root){
    int mx=-1,op;
queue<TreeNode<int>*>q;
    q.push(root);
    while(q.size()!=0){
        TreeNode<int>*front=q.front();
    int x=0;
        x=front->data;
        for(int i=0;i<front->children.size();i++){
            x+=front->children[i]->data;
            q.push(front->children[i]);
        }
        if(mx<x){
            op=front->data;
            mx=x;
        }
        q.pop();
    }
    return op;
}
int main(){
TreeNode<int>* root=takeinput();
cout<<maxsum(root)<<endl;
return 0;
}