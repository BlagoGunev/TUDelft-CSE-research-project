#include <bits/stdc++.h>
using namespace std;
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); } } _;

const int N = 100007;
int p1[N], p2[N], p3[N];

int main()
{
    //freopen("i.in","r",stdin);
    //freopen("o.out","w",stdout);
    string s; cin >> s; int n = ((int)((s).size()));
    for(int i = 1; i <= n; ++i)
        p1[i] = (s[i-1] == 'x') + p1[i-1], p2[i] = (s[i-1] == 'y') + p2[i-1], p3[i] = (s[i-1] == 'z') + p3[i-1];

    int m; cin >> m;
    while(m--)
    {
        int l, r; cin >> l >> r; --l;
        int x = p1[r] - p1[l], y = p2[r] - p2[l], z = p3[r] - p3[l];

        if((r-l) <= 2 or max(max(x, y), z) - min(min(x, y), z) <= 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}