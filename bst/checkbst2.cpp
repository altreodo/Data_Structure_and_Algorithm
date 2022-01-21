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
class Bstdata{
    public:
    int maximum;
    int minimum;
    bool isbst;
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
Bstdata check(BST<int>*root){
    if(root==NULL){
        Bstdata output;
        output.maximum=INT_MIN;
        output.minimum=INT_MAX;
        output.isbst=true;
        return output;
    }
    Bstdata leftoutput=check(root->left);
    Bstdata rightoutput=check(root->right);
    int maximum=max(root->data,max(leftoutput.maximum,rightoutput.maximum));
    int minimum=min(root->data,min(leftoutput.minimum,rightoutput.minimum));
    bool ot=(leftoutput.maximum<root->data)&&(rightoutput.minimum>=root->data)&&leftoutput.isbst && rightoutput.isbst;
    Bstdata output;
    output.maximum=maximum;
    output.minimum=minimum;
    output.isbst=ot;
    return output;
}
int main(){
BST<int>*root=takeinput();
Bstdata ans=check(root);
if(ans.isbst){
    cout<<"true";
}else{
    cout<<"false";
}
return 0;
}