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
bool search(Binarytree<int>*root,int n){
    if(root==NULL){
        return false;
    }
    if(root->data==n){
        return true;
    }
    if(search(root->left,n)  || search(root->right,n)){
        return true;
    }
    return false;
}
int lca(Binarytree<int>*root,int node1,int node2){
    if(root==NULL){
        return -1;
    }
    bool nd1=search(root->left,node1);
    bool nd11=search(root->right,node1);
    bool nd2=search(root->left,node2);
    bool nd21=search(root->right,node2);
    if(root->data==node1 && (nd2 || nd21)){
        return root->data;
    }else if(root->data==node2 && (nd1 || nd11)){
        return root->data;
    }else if((nd1 && nd21) ){
        return root->data;
    }else if(nd11 && nd2){
        return root->data;
    }else{
        if( lca(root->left,node1,node2)==-1){
        return lca(root->right,node1,node2);
        }else{
            return lca(root->left,node1,node2);
        }
    }
    return -1;
}
int main(){
    Binarytree<int>*root;
    root=takeinput();
    int node1,node2;
    cin>>node1>>node2;
     int op=lca(root,node1,node2);
     cout<<op<<endl;
return 0;
}