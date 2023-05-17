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
map<int,int> find(Binarytree<int>* root,map<int,int>&p,int i,int k){
if(root==NULL){
    return p;
}
if(root->data+i==k && root->data!=9999999){
    p.insert({i,root->data});
    root->data=9999999;
}
p=find(root->left,p,i,k);
p=find(root->right,p,i,k);
return p;
}
map<int,int> pairsum(Binarytree<int>*root,map<int,int>&p,int k,Binarytree<int>*pt){
  if(root==NULL){
      return p;
  }
  p=find(pt,p,root->data,k);
  p=pairsum(root->left,p,k,pt);
  p=pairsum(root->right,p,k,pt);
  return p;
}
int main(){
    Binarytree<int>*root;
    root=takeinput();
    int k;
    cin>>k;
    map<int,int>p;
    p=pairsum(root,p,k,root);
    map<int,int>::iterator it=p.begin();
while(it!=p.end()){
    cout<<(*it).first<<" "<<(*it).second<<endl;
    it++;
}
return 0;
}