#include <bits/stdc++.h>
#define int long long
#define ll pair <long long,long long>
using namespace std;

long long a[200002];

signed main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i5=1;i5<=t;i5++)
    {
        int n;
        cin >> n;
        vector<int> v,v2;
        for (int i=1;i<=n;i++) 
        {
            cin >> a[i];
            if (a[i]%2==0) v.push_back(a[i]);
            else v2.push_back(a[i]);
        }
        sort (v.begin(),v.end());
        sort (v2.begin(),v2.end());
        int i3=0,i4=0;
        int kt=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i]%2==0)
            {
                i3++;
                a[i]=v[i3-1];
            }
            else
            {
                i4++;
                a[i]=v2[i4-1];
            }
            if (a[i]>=a[i-1])
            {
                continue;
            }
            kt=-1;
            break;
            
        }
        if (kt==0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}