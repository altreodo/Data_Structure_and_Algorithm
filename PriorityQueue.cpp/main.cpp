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
    }
    void insert(int k)
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
            }else{
                break;
            }
            child = parent;
        }
    }
    void output(){
        for(int i=0;i<pq.size();i++){
            cout<<pq[i]<<" ";
        }
    }
};
int main()
{
ProrityQueue obj;
obj.insert(3);
obj.insert(17);
obj.insert(23);
obj.insert(1);
obj.insert(10);
obj.insert(9);
obj.output();
    return 0;
}