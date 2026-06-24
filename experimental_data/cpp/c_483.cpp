#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int l = 1, r = n;
    for(int i = 1; i <= k; ++i)
    {
        if(i % 2 == 1)
        {
            cout<<l++<<" ";
        }
        else
        {
            cout<<r--<<" ";
        }
    }
    
    if(k % 2 == 1)
    {
        for(int i = l; i <= r; ++i)
        {
            cout<<i<<" ";
        }
    }
    else
    {
        for(int i = r; i >= l; --i)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}