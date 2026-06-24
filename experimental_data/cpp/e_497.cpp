// LUOGU_RID: 161670944
#include <bits/stdc++.h>
using namespace std;

char *p1, *p2, buf[1048577];
#define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)
template <typename T>
inline void Read(T &x)
{
    x = 0; char ch = gc;
    while (!isdigit(ch)) ch = gc;
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc;
}

typedef long long ll;
typedef pair<int, ll> pii;
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;

ll n;
int k, md[105], lst[105], w[105];

struct matrix
{
    ll c[35][35];
    matrix() { memset(c, 0, sizeof(c)); }
    matrix operator * (const matrix &b)const 
    {
        matrix ans;
        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= k; j++)
                for (int l = 0; l <= k; l++)
                    (ans.c[i][j] += c[i][l] * b.c[l][j]) %= mod;
        return ans;
    }
    void shift(int p)
    {
        while (p--)
        {
            matrix ans;
            for (int i = 0; i < k; i++)
                for (int j = 0; j < k; j++)
                    ans.c[md[i + 1]][md[j + 1]] = c[i][j];
            for (int i = 0; i < k; i++)
                ans.c[md[i + 1]][k] = c[i][k];
            for (int i = 0; i < k; i++)
                ans.c[k][md[i + 1]] = c[k][i];
            ans.c[k][k] = c[k][k];
            (*this) = ans;
        }
    }
}f[65];

ll ans[35], tmp[35];
void pmul(matrix &b)
{
    for (int i = 0; i <= k; i++)
    {
        tmp[i] = 0;
        for (int j = 0; j <= k; j++)
            (tmp[i] += ans[j] * b.c[j][i]) %= mod;
    }
    for (int i = 0; i <= k; i++) ans[i] = tmp[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < k; i++) md[i] = i;
    for (int i = k; i < 2 * k; i++) md[i] = i - k;
    int m = 0; ll lim = 1;
    while (lim <= n / k) m++, lim *= k;
    lim = n;
    for (int i = 0; i <= m; i++) w[i] = lim % k, lim /= k;

    f[0].c[k][k] = 2; f[0].c[k][0] = 1; f[0].c[0][k] = mod - 1; lst[0] = 0;
    for (int i = 1; i < k; i++) f[0].c[i][i] = 1;
    for (int i = 1; i <= m; i++)
    {
        matrix tmp = f[i - 1]; f[i] = tmp;
        for (int j = 1; j < k; j++)
        {
            tmp.shift(1);
            f[i] = f[i] * tmp;
        }
        lst[i] = md[lst[i - 1] + k - 1];
    }

    ans[k] = 1;
    int ls = 0;
    for (int i = m; ~i; i--)
    {
        f[i].shift(ls);
        for (int j = 0; j < w[i]; j++)
        {
            pmul(f[i]);
            f[i].shift(1);
            ls = md[ls + 1];
        }
    }
    cout << ans[k];
    return 0;
}