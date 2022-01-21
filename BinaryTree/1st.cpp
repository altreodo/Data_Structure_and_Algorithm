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
//non level wise
// Binarytree<int>*takeinput(){
//     int rootdata;
//     cout<<"enter the data ";
//     cin>>rootdata;
//     if(rootdata==-1){
//         return NULL;
//     }
//     Binarytree<int>*root=new Binarytree<int>(rootdata);
//     Binarytree<int>*leftchild=takeinput();
//     Binarytree<int>*rightchild=takeinput();
//     root->left=leftchild;
//     root->right=rightchild;
//     return root;
// }
//level wise
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
//Non level wise
// void print(Binarytree<int>*root){
//     if(root==NULL){
//         return;
//     }
//     cout<<root->data<<":";
//     if(root->left!=NULL){
//         cout<<"L"<<root->left->data<<" ";
//     }
//     if(root->right!=NULL){
//         cout<<"R"<<root->right->data<<" ";
//     }
//     cout<<endl;
//     print(root->left);
//     print(root->right);
// }
//level wise
void print(Binarytree<int>*root){
    queue<Binarytree<int>*>q;
    q.push(root);
    while (!q.empty())
    {
        Binarytree<int>*root=q.front();
        q.pop();
        cout<<root->data<<": ";
        if(root->left!=NULL){
        Binarytree<int>*left=root->left;
        cout<<"L:"<<left->data<<",";
        q.push(left);
        }else{
            cout<<"L:"<<-1<<",";
        }
        if(root->right!=NULL){
        Binarytree<int>*right=root->right;
        cout<<"R:"<<right->data<<" ";
        q.push(right);
        }else{
            cout<<"R:"<<-1<<",";
        }
        cout<<endl;
    }
    
}
int main(){
Binarytree<int>*root=takeinput();
print(root);
return 0;
}