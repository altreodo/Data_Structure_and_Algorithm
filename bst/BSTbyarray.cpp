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
void print(BST<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
BST<int>* input(int ar[],int strt,int end){
    if(strt>end){
        return NULL;
    }
    int mid=(strt+end)/2;
    int data=ar[mid];
    BST<int>* left=input(ar,strt,mid-1);
    BST<int>* right=input(ar,mid+1,end);
    BST<int>*root=new BST<int>(data);
    root->left=left;
    root->right=right;
    return root;
}
int main(){
int n;
cin>>n;
int ar[n];
for(int i=0;i<n;i++){
    cin>>ar[i];
}
BST<int>*root=input(ar,0,n-1);
print(root);
return 0;
}