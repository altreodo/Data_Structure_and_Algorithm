#include<bits/stdc++.h>
using namespace std;
  class List {
      public:
          int data;
          List *next;

          List(int val) {
              this->data = val;
              next = NULL;
          }
          ~List() {
              if (next != NULL) {
                  delete next;
              }
          }
   };

int finder(List* head){
    if(head==NULL){
        return 0;
    }
    return 1+finder(head->next);
}
void foldAndMerge(List *head) {

 vector<int>v1,v2;
   // Write your code here.
    int l=finder(head);
    List *op1=head;
    int j=l/2;
    while(j>0){
    v1.push_back(op1->data);
    j--;
    op1=op1->next;
    }
    j=l/2;
    while(j>0){
    v2.push_back(op1->data);
    j--;
    op1=op1->next;
    }
    List*hea=NULL;
    List*tail=NULL;
    reverse(v1.begin(),v1.end());
    //cout<<v1[0]<<"<<<<";
    int k=0;
    while(k<l/2){
        List* n=new List(v1[k]*v2[k]);
        if(hea==NULL){
            hea=n;
            tail=n;
        }else{
            tail->next=n;
            tail=tail->next;
        }
        k++;
    }
    List* n=new List(-1);
    if(hea==NULL){
            hea=n;
            tail=n;
        }else{
            tail->next=n;
            tail=tail->next;
        }
    tail=NULL;
    //return hea;
}
int main(){
    List *n=new List(4);
    List *op=new List(8);
    List *head=NULL;
    List*tail=NULL;
    head=n;
    tail=n;
    tail->next=op;
    tail=tail->next;
foldAndMerge(head);
}