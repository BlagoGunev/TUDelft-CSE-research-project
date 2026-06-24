#include<bits/stdc++.h>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    long long int n ,j, k , p;
    cin>>n;
    if(n%4==0)
        cout<<"0";
    else
    {
        k=n/2;
        if(n%2==0)
        {
            if(k%2==0)
                cout<<"0";
            else
                cout<<"1";
        }
        else
        {
            if(k%2==0)
            {
                cout<<"1";
            }
            else
                cout<<"0";
        }
    }
    return 0;
}