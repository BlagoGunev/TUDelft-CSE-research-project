#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    bool f = 0;
    string a = "", b = "";
    for (int i = 0; i < n; i++)
    {
        if (!f && s[i] != t[i])
        {
            a += max(s[i], t[i]), b += min(s[i], t[i]);
            f = 1;
            continue;
        }
        a += min(s[i], t[i]), b += max(s[i], t[i]);
    }
    cout << a << endl
         << b << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}