#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define mes(a, val) memset(a, val, sizeof a)
#define mec(b, a) memcpy(b, a, sizeof a)


const int maxn = 1e4 + 10;

int main()
{
    int n;scanf("%d", &n);
    int x = 0, y = 0;
    int a, b;
    int cnt = 1;
    while(n --)
    {
        scanf("%d %d", &a, &b);
        if(a == x && b == y)continue;
        else if(a == x)
        {
            if(a <= b && a > y)cnt ++;
        }
        else if(b == y)
        {
            if(b <= a && b > x)cnt ++;
        }
        else
        {
            int mi = min(a, b), ma = max(x, y);
            if(mi == ma && x != y)cnt ++;
            else if(mi > ma)
            {
                cnt += (mi - ma);
                if(x != y)cnt ++;
            }

        }

        x = a; y = b;
    }
    printf("%d\n", cnt);
    return 0;
}