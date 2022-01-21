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
// void print(TreeNode<int>*root){
//     queue<TreeNode<int>*>q;
//     q.push(root);
//     while(q.size()!=0){
//         TreeNode<int>*front=q.front();
//         cout<<front->data<<" ";
//         for(int i=0;i<front->children.size();i++){
//             q.push(front->children[i]);
//         }
//         q.pop();
//     }
// }
void replace(TreeNode<int>*root,int m){
    root->data=m;
    for(int u=0;u<root->children.size();u++){
        int n=m;
        replace(root->children[u],m+1);
        m=n;
    }
}
void print(TreeNode<int>*root){
    if(root->children.size()==0){
        return;
    }
    //cout<<root->data<<endl;
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ";
}
cout<<endl;
for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
}
}
int main(){
TreeNode<int>* root=takeinput();
replace(root,0);
cout<<0<<endl;
print(root);
return 0;
}