#include<bits/stdc++.h>
using namespace std;
class Trienode{
public:
char data;
Trienode**children;
bool isterminal;
Trienode(char data){
    this->data=data;
    children=new Trienode*[26];
    for(int i=0;i<26;i++){
        children[i]=NULL;
    }
    isterminal=false;
}
};
class trie{
Trienode*root;
public:
trie(){
    root=new Trienode('\0');
}
void insert(Trienode * root,string word){
    if(word.size()==0){
        root->isterminal=true;
        return;
     }
     int index=word[0]-'a';
     Trienode * child;
     if(root->children[index]!=NULL){
         child=root->children[index];
     }else{
         child=new Trienode(word[0]);
         root->children[index]=child;
     }
     insert(child,word.substr(1));
}
bool searchr(Trienode * root,string word){
    if(word.length()==0){
        if(root->isterminal){
          return true;
        }
        return false;
    }
    int index=word[0]-'a';
    if(root->children[index]==NULL){
        return false;
    }
    return searchr(root->children[index],word.substr(1));
}
void remove(Trienode* root,string word){
    if(word.length()==0){
    root->isterminal=false;
    return ;
    }
    int index=word[0]-'a';
    if(root->children[index]==NULL){
        return;
    }
    remove( root->children[index], word.substr(1));
}
};
int main(){
trie obj;
Trienode*root;
string s;
cin>>s;
obj.insert(root,s);
string op;
cin>>op;
if(obj.searchr(root,op)){
    cout<<"YES"<<endl;
}else{
    cout<<"NO"<<endl;
}
return 0;
}