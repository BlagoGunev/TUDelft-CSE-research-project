#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include "bits/stdc++.h"
using namespace std;
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fios ofstream out("test.txt");cout.rdbuf(out.rdbuf())
#define endl "\n"
#define lowbit(x) (x & (-x))
#define INF 0x3f3f3f3f
#define MINF 2147483647
#define eps 1e-6
#define PI acos(-1)
typedef unsigned long long ULL;
typedef long long LL;
#define int long long
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 200010;

int n;
int a[N];

signed main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(a, 0, sizeof a);
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];

        int res = 0;
        for(int i = 1; i <= n; i++)
            if(a[i] > a[i + 1]) res += a[i] - a[i + 1];

        cout << res - 1 << endl;
    }

    return 0;
}