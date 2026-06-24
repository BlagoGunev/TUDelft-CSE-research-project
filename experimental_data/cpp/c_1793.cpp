#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <set>
#include <numeric>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    int minx = INT_MAX, maxx = 0;
    for( int i = 0 ; i < n ; i++ )
    {
        cin>>a[i];
        minx = min(minx, a[i]);
        maxx = max(maxx, a[i]);
    }
    int l = 0, r = n-1;
    int ans = 0;
    while( l < r )
    {
        if( a[l] != maxx && a[l] != minx && a[r] != minx && a[r] != maxx )
        {
            ans = 1;
            break;
        }
        if( a[l] == maxx )
            maxx--, l++;
        else if( a[r] == maxx )
            maxx--, r--;
        if( a[l] == minx )
            minx++, l++;
        else if( a[r] == minx )
            minx++, r--;
    }
    if( ans )
        cout<<l+1<<" "<<r+1<<"\n";
    else
        cout<<"-1\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}