#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <iterator>
#define vi vector<int>
#define rep(i, x, y) for (int i = x; i < y; i++)
#define ff first
#define mii map<int, int>
#define pii pair<int, int>
#define setbits(x) __builtin_popcountll(x)
#define ss second
#define all(x) x.begin(), x.end()
#define vii vector<vector<int>>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
const int mod = 1e9 + 7;
const int nod = 998244353;
//
int32_t main()
{

    fast

        int t,
        a, b, c, i, j, x, y, z, h, d, e, n, m, k;

    t = 1;
    cin >> t;
    while (t--)
    {
        cin >> a >> x >> b >> y >> c >> z;
        if(x==y)
        {
            if(z>y) cout << "0\n";
            else cout << abs(a-b)<< "\n";
        }
        else if(y==z)
        {
            if(x>y) cout << "0\n";
            else cout << abs(b-c)<< "\n";
        }
        else if(z==x)
        {
            if(y>z) cout << "0\n";
            else 
            cout << abs(a-c) << "\n";
        }
        else cout << "0\n";
    }
    return 0;
}