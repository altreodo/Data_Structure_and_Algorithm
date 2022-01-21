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

void secondlargest(TreeNode<int>*root,int* max1,int* max2){
    int s=root->data;
    if(s>=*max1){
        *max2=*max1;
        *max1=s;
    }else if(s<*max1 & s>*max2){
        *max2=s;
    }
    for(int i=0;i<root->children.size();i++){
        secondlargest(root->children[i],max1,max2);
    }
}
int main(){
TreeNode<int>* root=takeinput();
int mx1=-1,mx2=-1;
secondlargest(root,&mx1,&mx2);
cout<<mx2;
return 0;
}