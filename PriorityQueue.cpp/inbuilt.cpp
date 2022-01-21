#include<iostream>
#include<queue>

using namespace std;
int main(){
priority_queue<int>q;
q.push(12);
q.push(13);
q.push(43);
q.push(89);
q.push(5);
cout<<q.size()<<endl;
while (!q.empty())
{
    cout<<q.top()<<" ";
    q.pop();
}

return 0;
}