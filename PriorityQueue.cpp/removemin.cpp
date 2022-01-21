#include <bits/stdc++.h>
using namespace std;
class ProrityQueue
{
    vector<int> pq;

public:
    ProrityQueue()
    {
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getsize()
    {
        return pq.size();
    }
    int getmin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }void insert(int k)
    {
        pq.push_back(k);
        int child = pq.size() - 1;
        while (child > 0)
        {
            int parent = (child - 1) / 2;
            if (pq[child] < pq[parent])
            {
                int temp = pq[child];
                pq[child] = pq[parent];
                pq[parent] = temp;
            }
            else
            {
                break;
            }
            child = parent;
        }
    }
    int get_min()
    {if(isEmpty()){
        return 0;
    }
        int ans=pq[0];
        pq[0] =pq[pq.size() - 1];
        pq.pop_back();
        int child1 = 1,child2=2,index=0;
        while(child1<pq.size()){
            int minindex=index;
        if(pq[minindex]>pq[child1]){
            minindex=child1;
        } if(pq[minindex]>pq[child2] && child2<pq.size()){
            minindex=child2;
        } if(index==minindex){
            break;
        }
        int temp=pq[minindex];
            pq[minindex]=pq[index];
            pq[index]=temp;
        index=minindex;
        child1=(index*2)+1;
        child2=(index*2)+2;
    }
    return ans;
    }
};
int main(){
    int n;
    cin>>n;
    ProrityQueue obj;
    while (n--)
    {
        int l;
        cin>>l;
        obj.insert(l);
    }
    while (!obj.isEmpty())
    {     
        cout<<obj.get_min()<<" ";
    }
    
}