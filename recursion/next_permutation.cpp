#include <iostream>
using namespace std;

int main()
{
        int size, count = 0; //size of array
        cin >> size;
        int p=size-1;
        int array[size];
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }
        while(p>0){
            if(array[p]>array[p-1]){
                int temp=array[p];
                array[p]=array[p-1];
                array[p-1]=temp;
                break;
            }else{
                p--;
            }
        }
        if(p==0){
            for (int i = size-1; i>=0; i--)
        {
            cout<< array[i]<<" ";
        }
        }else{
             for (int i = 0; i<size; i++)
        {
            cout<< array[i]<<" ";
        }
        }
    return 0;
}