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
    ~Binarytree(){
        delete left;
        delete right;
    }
};
Binarytree<int>* takeinput(){
    queue<Binarytree<int>*>q;
    int rootdata;
    cout<<"enter the data ";
    cin>>rootdata;
    Binarytree<int>*root=new Binarytree<int>(rootdata);
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
void print(Binarytree<int>*root){
    queue<Binarytree<int>*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        if(q.front()==NULL){
            cout<<endl;
            q.pop();
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }else{
        Binarytree<int>*root=q.front();
        q.pop();
        cout<<root->data<<" ";
        if(root->left!=NULL){
        Binarytree<int>*left=root->left;
        q.push(left);
        }
        if(root->right!=NULL){
        Binarytree<int>*right=root->right;
        q.push(right);
        }
        }
    }
    
}
Binarytree<int>* remove(Binarytree<int>*root){
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    if(root->left!=NULL){
     root->left=remove(root->left);
    }
    if(root->right!=NULL){
     root->right=remove(root->right);
    }
    return root;
}
int main(){
Binarytree<int>*root=takeinput();
Binarytree<int>*u=remove(root);
print(u);
return 0;
}