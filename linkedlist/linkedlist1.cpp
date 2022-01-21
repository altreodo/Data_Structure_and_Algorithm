#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
void linkedlist(struct node * ptr){
    while(ptr!=NULL){
    cout<<ptr->data;
    ptr=ptr->next;
    }
}
int main(){
    struct node * head;
    struct node *second;
    head=(struct node*) malloc(sizeof(struct node));
    second=(struct node*) malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=9;
    second->next=NULL;
    linkedlist(head);
return 0;
}