#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int n, i, x, ans, s;

//asdasdasd

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        if(x==-1&&s==0)ans++; else s+=x;
    }
    cout<<ans;
}