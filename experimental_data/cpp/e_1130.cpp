#include <bits/stdc++.h>
using namespace std;
const int pmax=(int)(1e6);
int main()
{
    ios_base::sync_with_stdio(0);
    srand(time(0));
    long long k;
    cin>>k;
    int n=(k+2+2*pmax-2)/(2*pmax-1);
    if ((k+(n+2))%2!=0) n++;
    if (n+2>2000)
    {
        cout<<"-1";
        return 0;
    }
    cout<<n+2<<endl;
    cout<<"1 -2 ";
    int sum=(k+n+2)/2;
    for (int i=0; i<n; i++)
    {
        cout<<min(sum,pmax)<<" ";
        sum-=min(sum,pmax);
    }
    return 0;
}