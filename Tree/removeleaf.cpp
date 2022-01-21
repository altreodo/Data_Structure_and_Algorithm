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
TreeNode<int>*remove(TreeNode<int>* root){
    if(root->children.size()==0){
        return NULL;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* np=remove(root->children[i]);
        root->children[i]=np;
    }
    return root;
}
void print(TreeNode<int>*root){
    queue<TreeNode<int>*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()!=0){
        if(q.front()==NULL){
            cout<<endl;
            q.pop();
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }
        TreeNode<int>*front=q.front();
        q.pop();
        cout<<front->data<<" ";
        for(int i=0;i<front->children.size();i++){
            //cout<<front->children[i]->data<<" ";
            q.push(front->children[i]);
        }
    }
}

int main(){
TreeNode<int>* root=takeinput();
TreeNode<int>* rt=remove(root);
print(root);
return 0;
}