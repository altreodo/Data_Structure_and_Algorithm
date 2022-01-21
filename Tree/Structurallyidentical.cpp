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
bool isidenticle(TreeNode<int>*root1,TreeNode<int>*root2){
if(root1->data!=root2->data || root1->children.size()!=root2->children.size()){
    return false;
}
for(int i=0;i<root1->children.size();i++){
    if(!isidenticle(root1->children[i],root2->children[i])){
        return false;
    }
}
return true;
}

int main(){
TreeNode<int>* root=takeinput();
TreeNode<int>*root2=takeinput();
if(isidenticle(root,root2)){
    cout<<"true"<<endl;
}else{
    cout<<"false"<<endl;
}
return 0;
}