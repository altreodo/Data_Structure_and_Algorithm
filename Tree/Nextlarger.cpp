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
int nextlargest(TreeNode<int>*root,int n){
    int mn=999999;
    queue<TreeNode<int>*>q;
    q.push(root);
while(q.size()!=0){
    TreeNode<int>*front=q.front();
    q.pop();
    if(front->data>n){
        mn=min(mn,front->data-n);
    }
    for(int y=0;y<front->children.size();y++){
        q.push(front->children[y]);
    }
}
return mn;
}
int nextlarge(TreeNode<int>*root,int n,int mn){
if(root->data>n){
    return root->data-n;
}
for(int i=0;i<root->children.size();i++){
    mn=min(mn,nextlarge(root->children[i],n,mn));
}
return mn;
}
int main(){
int u;
cin>>u;
TreeNode<int>* root=takeinput();
if(nextlarge(root,u,99999)==99999){
    cout<<-1;
}else{
cout<<u+nextlarge(root,u,99999);
}
return 0;
}