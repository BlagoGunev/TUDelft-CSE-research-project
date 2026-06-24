# include <cstdio>
# include <algorithm>
# define MAXN 200005
using namespace std;

int n, k;
int a[MAXN];
long long m[11][MAXN];

inline int cal(int i)
{
    int ret = 0;
    while (i)
    {
        ++ret;
        i /= 10;
    }
    return ret;
}

inline int cal2(int i, int tar)
{
    return upper_bound(m[i], m[i] + n, tar) - upper_bound(m[i], m[i] + n, tar - 1);
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        m[0][i] = a[i] % k;
        for (int j = 1; j < 11; ++j)
            m[j][i] = m[j-1][i] * 10 % k;
    }
    for (int i = 1; i < 11; ++i)
        sort(m[i], m[i] + n);
    /*for (int i = 0; i < 6; ++i)
        for (int j = 0; j < n; ++j)
            printf("%d%c", m[i][j], " \n"[j==n-1]);*/
    long long tot = 0;
    for (int i = 0; i < n; ++i)
    {
        int mod = m[0][i];
        int len = cal(a[i]);
        //printf("%d %d\n", mod, len);
        tot += cal2(len, (k - mod) % k);
        long long nmod = mod;
        while (len--)
            nmod = nmod * 10 % k;
        if ((mod + nmod) % k == 0)
            --tot;
    }

    printf("%lld", tot);

    return 0;
}