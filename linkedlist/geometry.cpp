#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        int n,q,op;
        cin>>n>>q;
        op=n;
        float sumx=0,sumy=0,cx,cy;
        vector<pair<int,int>>v;
        while(n--){
           int x,y;
            cin>>x>>y;
            v.push_back({x,y});
            sumx+=x;
            sumy+=y;
        }
        cx=sumx/op;
        cy=sumy/op;
        while(q--){
          float vt,t,r,sum=0;
          cin>>vt>>t;
          r=vt*t;
        for(int h=0;h<op;h++){
            int k=(h+1)%op,k2=(h)%op;
            int a=v[k].first;
            int b=v[k].second;
            int x1=v[k2].first;
            int y1=v[k2].second;
            //cout<<a<<" "<<b<<" "<<x1<<" "<<y1<<" ";
            float dis=sqrt(pow(a-x1,2)+pow(y1-b,2));
            float dis2=(abs(((y1-b)*cx)-((x1-a)*cy)-((y1-b)*a)+((x1-a)*b)))/dis;
            float l=((dis2+r)*dis)/dis2;
            //cout<<dis<<" "<<dis2<<" "<<l<<" ";
            sum+=(0.5)*l*(dis2+r);
        }
        float num=sum;
        printf("%0.7f",num);
        cout<<endl;
        }
    }
}