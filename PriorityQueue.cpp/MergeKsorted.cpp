#include<bits/stdc++.h>
using namespace std;
class triplet{
    public:
    int ele;
    int ind;
    vector<int>vc;
};
struct  compare
{
   bool operator()(triplet const& p1,triplet const& p2){
    return p1.ele > p2.ele;
   }
};

int main(){
int k;
cin>>k;
priority_queue<triplet,vector<triplet>,compare> q;
for(int i=0;i<k;i++){
    int n;
    cin>>n;
    vector<int>vk;
    for(int y=0;y<n;y++){
        int op;
        cin>>op;
        vk.push_back(op);
    }
    triplet lp;
    lp.ele=vk[0];
    lp.ind=0;
    lp.vc=vk;
    q.push(lp);
}
//q.pop();
//q.top().ind=q.top().ind+1;
//cout<<q.top().ele<<" "<<q.top().ind;
while (!q.empty())
{
    triplet op=q.top();
 cout<<op.ele<<" ";
op.ind=op.ind+1;
 if(op.ind<op.vc.size()){
     int h=op.ind;
     op.ele=op.vc[h];
     q.pop();
     q.push(op);
 }else{
     q.pop();
 }
}

return 0;
}