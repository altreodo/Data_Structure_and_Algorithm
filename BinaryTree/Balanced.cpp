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
    if(rootdata==-1){
        return NULL;
    }
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
int height(Binarytree<int>*root){
    if(root==NULL){
        return 0;
    }
    return max(1+height(root->left),1+height(root->right));
}
bool check(Binarytree<int>*root){
    if(root==NULL){
        return true;
    }
    if(abs(height(root->left)-height(root->right))>1){
        return false;
    }
    if(check(root->left) &&  check(root->right)){
        return true;
    }
       return false;

}
int main(){
Binarytree<int>*root=takeinput();
if(check(root)){
    cout<<"true"<<endl;
}else{
    cout<<"false"<<endl;
}
return 0;
}