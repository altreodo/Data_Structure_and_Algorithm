#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BST{
    public:
    T data;
    BST*left;
    BST*right;
    BST(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BST(){
        delete left;
        delete right;
    }
};
class dta{
public:
int mx;
vector<int>vt;
};
BST<int>* takeinput(){
    queue<BST<int>*>q;
    int rootdata;
    cout<<"enter the data ";
    cin>>rootdata;
    BST<int>*root=new BST<int>(rootdata);
    q.push(root);
    while(!q.empty()){
        BST<int>*root=q.front();
        q.pop();
        int leftdata,rightdata;
        cin>>leftdata>>rightdata;
        if(leftdata!=-1){
        BST<int>*left=new BST<int>(leftdata);
        q.push(left);
        root->left=left;
        }else{
             root->left=NULL;
        }
        if(rightdata!=-1){
        BST<int>*right=new BST<int>(rightdata);
        q.push(right);
        root->right=right;
        }else{
            root->right=NULL;
        }
    }
    return root;
}
dta maximun(BST<int>*root,vector<int>&v){
    if(root==NULL){
    vector<int>ve;
        dta obj;
        obj.mx=0;
        obj.vt=ve;
        return obj;
    }
    dta obj,o1,o2;
    o1=maximun(root->left,v);
    o2=maximun(root->right,v);
    obj.mx=max(o1.mx+1,o2.mx+1);
    vector<int>ve;
    ve.push_back(root->data);
    if(o1.mx>=o2.mx){
         for(int y=0;y<o1.vt.size();y++){
             ve.push_back(o1.vt[y]);
         }
    }else if(o1.mx<o2.mx){
     for(int y=0;y<o2.vt.size();y++){
             ve.push_back(o2.vt[y]);
         }
    }
    obj.vt=ve;
    return obj;
}
int main(){
BST<int>*root=takeinput();
vector<int>v;
dta op=maximun(root,v);
for(int y=0;y<op.vt.size();y++){
    cout<<op.vt[y]<<"->";
}
return 0;
}