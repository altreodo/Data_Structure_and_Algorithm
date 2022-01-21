#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Binarytree{
    public:
    T data;
    Binarytree*left;
    Binarytree*right;
    Binarytree(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~ Binarytree(){
        delete left;
        delete right;
    }
};
 Binarytree<int>* takeinput(){
    queue< Binarytree<int>*>q;
    int rootdata;
    cout<<"enter the data ";
    cin>>rootdata;
     Binarytree<int>*root=new  Binarytree<int>(rootdata);
    q.push(root);
    while(!q.empty()){
         Binarytree<int>*root=q.front();
        q.pop();
        int leftdata,rightdata;
        cin>>leftdata>>rightdata;
        if(leftdata!=-1){
        Binarytree<int>*left=new Binarytree<int>(leftdata);
        q.push(left);
        root->left=left;
        }else{
             root->left=NULL;
        }
        if(rightdata!=-1){
         Binarytree<int>*right=new Binarytree<int>(rightdata);
        q.push(right);
        root->right=right;
        }else{
            root->right=NULL;
        }
    }
    return root;
}
vector<int> path(Binarytree<int>* root,int k,vector<int>&v){
 if(root==NULL){
     return v;
 }
 if(root->data==k){
     v.push_back(k);
     return v;
 }
 if(path(root->left,k,v).size()!=0){
     v.push_back(root->data);
     return v;
 }else if(path(root->right,k,v).size()!=0){
     v.push_back(root->data);
     return v;
 }
 return v;
}
int main(){
 Binarytree<int>*root=takeinput();
int k;
cin>>k;
vector<int> v;
v=path(root,k,v);
for(int y=0;y<v.size();y++){
    cout<<v[y]<<" ";
}
return 0;
}