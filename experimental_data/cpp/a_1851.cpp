#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
string s = "abcdefghijklmnopqrstuvwxyz";

void solution()
{
    int res = 0;
    int n, m, k, H, h;
    cin >> n >> m >> k >> H;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        if (abs(H-h) <= (m-1)*k && abs(H-h) % k == 0 && H-h != 0) res++;
    }
    cout << res;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
        cout << endl;
    }
}