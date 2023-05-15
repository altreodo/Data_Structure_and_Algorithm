#include <bits/stdc++.h>
using namespace std;
// Kahn's Algorthm
bool kahnalgo(vector<vector<int>> &ed, int *ind, int n)
{
    queue<int> q;
    for (int y = 0; y < n; y++)
    {
        //cout<<ind[y]<<"-";
        if (ind[y] == 0)
        {
            q.push(y);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        count++;
        int j = q.front();
        q.pop();
       // cout<<j<<" ";
        for (auto it : ed[j])
        {
            ind[it]--;
            if (ind[it] == 0)
            {
               // cout<<it<<"+"<<ind[it]<<" ";
                q.push(it);
            }
        }
    }
    if (count == n)
        return false;
    return true;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n);
    int *indegree = new int[n];
    for (int y = 0; y < n; y++)
    {
        indegree[y] = 0;
    }
    for (int y = 0; y < e; y++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        indegree[v]++;
    }
    if (kahnalgo(edges, indegree, n))
    {
        cout << "Yes it have cycle";
    }
    else
    {
        cout << "No it does not have cycle";
    }
}