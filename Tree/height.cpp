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
void print(TreeNode<int>*root){
    queue<TreeNode<int>*>q;
    q.push(root);
    while(q.size()!=0){
        TreeNode<int>*front=q.front();
        cout<<front->data<<": ";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<" ";
            q.push(front->children[i]);
        }
        cout<<endl;
        q.pop();
    }
}
int height(TreeNode<int>*root,int s){
    if(root->children.size()==0){
        return 1;
    }
    for(int i=0;i<root->children.size();i++){
     s=max(s,1+height(root->children[i],s));
    }
    return s;
}

int main(){
TreeNode<int>* root=takeinput();
print(root);
cout<<"height of tree is"<<height(root,1);
return 0;
}