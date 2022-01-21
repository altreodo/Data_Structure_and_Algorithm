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
void path(Binarytree<int>*root,int k,vector<int>&v){
    if(root==NULL){
        return;
    }
    k=k-root->data;
    if(k==0 && root->left==NULL && root->right==NULL){
        v.push_back(root->data);
        vector<int>::iterator it=v.begin();
        while ((it!=v.end()))
        {
            cout<<(*it)<<" ";
            it++;
        }
        cout<<endl;
        return;
    }
    if(k>0){
        v.push_back(root->data);
    }
    path(root->left,k,v);
    if(v.size()>0){
    v.pop_back();
    }
    path(root->right,k,v);
}
int main(){
    Binarytree<int>*root;
    root=takeinput();
    int k;
    cin>>k;
    vector<int>v;
    path(root,k,v);
    return 0;
}