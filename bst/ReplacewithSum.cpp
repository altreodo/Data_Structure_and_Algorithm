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
int sum(Binarytree<int>*root){
    if(root==NULL){
        return 0;
    }
    return root->data+sum(root->left)+sum(root->right);
}
void replce(Binarytree<int>* root,int pt){
    if(root==NULL){
        return;
    }
    root->data=pt+root->data+sum(root->right);
    replce(root->left,root->data);
    replce(root->right,pt);
}
void output(Binarytree<int>*root){
    queue<Binarytree<int>*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        if(q.front()==NULL){
            q.pop();
            if(q.empty()){
                break;
            }
            cout<<endl;
            q.push(NULL);
        }else{
    Binarytree<int>* head=q.front();
    q.pop();
    cout<<head->data<<" ";
    if(head->left!=NULL){
        Binarytree<int>* left=head->left;
        q.push(left);
    }if(head->right!=NULL){
        Binarytree<int>* right=head->right;
        q.push(right);
    }
    }
    }
}
int main(){
    Binarytree<int>*root;
    root=takeinput();
    replce(root,0);
    output(root);
    return 0;
}