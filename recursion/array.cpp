#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; //test cases
    cin >> t;
    while (t--)
    {
        int size,y=0, count = 0; //size of array
        cin >> size;
        int array[size];
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }
        sort(array, array + size);
        while(y<size)
        {
            if (array[y] == array[y + 1])
            {
                count++;
                y++;
            }
            y++;
        }
        
            cout<<count<<endl;
    }
    return 0;
}