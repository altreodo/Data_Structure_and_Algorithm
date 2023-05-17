#include <bits/stdc++.h>
using namespace std;
class Stack
{
    int ar[100000] = {-1};
    int size, i = 0;

public:
    Stack(int n)
    {
        size = n;
    }
    void push(int k)
    {
        if (i == size)
        {
            cout << "Size is full\n";
        }
        ar[i] = k;
        i++;
    }
    void pop()
    {
        if (i == 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        ar[i] = -1;
        i--;
    }
    int top()
    {
        if (i > 0)
        {
            return ar[i - 1];
        }
        return -1;
    }
    bool isfull()
    {
        if (i == size)
        {
            return true;
        }
        return false;
    }
    bool isempty()
    {
        if (i == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    Stack obj = Stack(n);
    obj.push(5);
    obj.push(10);
    cout << obj.top() << '\n';
    if (obj.isempty())
    {
        cout << "Stack is empty\n";
    }
    obj.pop();
    cout << obj.top() << '\n';
}