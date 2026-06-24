#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;
vector<int> v3;
void Onigiri()
{
    int n;
    cin>>n;
    
    int x=1;
    int cnt=1;
    while(x<2*n+1)
    {
        x*=3;cnt++;
    }
    
    int num=0;
    for(int i=0;i<cnt;i++)
    {   
        num+=v3[i];
    }

    for (int i = cnt;i>=0;--i)
    {
        if(num-v3[i]>=n)
        {
            num-=v3[i];
        }

    }
    printf("%lld",num);
}

signed main()
{

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int x=1;
    for(int i=0;i<39;i++)
    {
        v3.push_back(x);
        x*=3;
    }
    //cout<<v3[v3.size()-2];
    int t = 1;
    cin >> t;
    while (t--)
    {
        Onigiri();
        cout<<endl;
    }
    return 0;
}