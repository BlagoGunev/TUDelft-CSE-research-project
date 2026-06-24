#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define ll long long
#define o1 first
#define o2 second
#define omp make_pair
#define opb push_back
#define opc pop_back()
#define inf 3423423423423423422ll
#define MAX_N 522222

using namespace std;

ll read(){ll x = 0;char c = 0;bool v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c < 33)c = getchar();return c;}

int n;
int c[MAX_N], lb[MAX_N], rb[MAX_N];
pair<int, int> a[MAX_N];

bool cmp(pair<int, int> a, pair<int, int> b) { return omp(a.o1, -a.o2) < omp(b.o1, -b.o2); }

bool solve()
{
    int cnt0 = 0, cnt1 = 0, l0 = 0, l1 = 0;
    for(int o = 1; o <= 2 * n; o++)
    {
        int l = o, r = o;
        for(int j = o; j <= 2 * n && a[j].o1 == a[o].o1 && (a[j].o2 > 0) == (a[o].o2 > 0); j++)
            r = j;
        o = r;
        if(a[l].o2 < 0)
        {
            for(int i = l; i <= r; i++)
                if(c[-a[i].o2])
                    cnt1--;
                else
                    cnt0--;
            if((cnt1 || cnt0) && cnt1 != 1 && cnt0 != 1)
                return 0;
            continue;
        }
        if(cnt0 > 1)
        {
            for(int i = l; i <= r; i++)
                c[a[i].o2] = 0, cnt0++, l0 = max(l0, rb[a[i].o2]);
            continue;
        }
        if(cnt1 > 1)
        {
            for(int i = l; i <= r; i++)
                c[a[i].o2] = 1, cnt1++, l1 = max(l1, rb[a[i].o2]);
            continue;
        }
        int p = l, mxr = rb[a[l].o2];
        for(int i = l + 1; i <= r; i++)
            if(rb[a[i].o2] > mxr)
                mxr = rb[a[i].o2], p = i;
        if(!cnt0 && !cnt1)
        {
            for(int i = l; i <= r; i++)
                if(i == p)
                    c[a[i].o2] = 0, cnt0++, l0 = max(l0, rb[a[i].o2]);
                else
                    c[a[i].o2] = 1, cnt1++, l1 = max(l1, rb[a[i].o2]);
            continue;
        }
        if(cnt0 && cnt1)
        {
            if(l0 <= l1)
                for(int i = l; i <= r; i++)
                    c[a[i].o2] = 0, cnt0++, l0 = max(l0, rb[a[i].o2]);
            else
                for(int i = l; i <= r; i++)
                    c[a[i].o2] = 1, cnt1++, l1 = max(l1, rb[a[i].o2]);
            continue;
        }
        if(cnt0 && !cnt1)
        {
            if(mxr > l0)
            {
                for(int i = l; i <= r; i++)
                    if(i == p)
                        c[a[i].o2] = 1, cnt1++, l1 = max(l1, rb[a[i].o2]);
                    else
                        c[a[i].o2] = 0, cnt0++, l0 = max(l0, rb[a[i].o2]);
            }
            else
                for(int i = l; i <= r; i++)
                    c[a[i].o2] = 1, cnt1++, l1 = max(l1, rb[a[i].o2]);
        }
        if(!cnt0 && cnt1)
        {
            if(mxr > l1)
            {
                for(int i = l; i <= r; i++)
                    if(i == p)
                        c[a[i].o2] = 0, cnt0++, l0 = max(l0, rb[a[i].o2]);
                    else
                        c[a[i].o2] = 1, cnt1++, l1 = max(l1, rb[a[i].o2]);
            }
            else
                for(int i = l; i <= r; i++)
                    c[a[i].o2] = 0, cnt0++, l0 = max(l0, rb[a[i].o2]);
        }
        if((cnt1 || cnt0) && cnt1 != 1 && cnt0 != 1)
            return 0;
    }
    return 1;
}

void oM()
{
    n = read();
    for(int i = 1; i <= n; i++)
        a[i] = omp(lb[i] = read(), i), a[i + n] = omp(rb[i] = read(), -i);
    sort(a + 1, a + 2 * n + 1, cmp);
    int cnt = 0, mxc = 0;
    for(int i = 1; i <= 2 * n; i++)
    {
        //printf("%d %d\n", a[i].o1, a[i].o2);
        if(a[i].o2 > 0)
            cnt++;
        else
            cnt--;
        if(i == 2 * n || a[i].o1 != a[i + 1].o1 || (a[i].o2 > 0) != (a[i + 1].o2 > 0))
            mxc = max(mxc, cnt);
    }
    if(mxc == 1)
    {
        printf("1\n");
        for(int i = 1; i <= n; i++)
            printf("1%c", " \n"[i == n]);
        return;
    }
    if(solve())
    {
        printf("2\n");
        for(int i = 1; i <= n; i++)
            printf("%c%c", "12"[c[i]], " \n"[i == n]);
        return;
    }
    for(int i = 1; i <= n; i++)
        c[i] = 0;
    int id = a[1].o2, nxt = a[1].o2, col = 1;
    c[id] = 1;
    for(int i = 2; i <= 2 * n; i++)
    {
        /*printf("%d %d %d %d\n", i, a[i].o2, id, nxt);
        for(int j = 1; j <= n; j++)
            printf("%d ", c[j]);
        printf("\n");*/
        if(a[i].o2 < 0)
        {
            if(a[i].o2 == -id)
            {
                col = 3 - col;
                if(rb[nxt] != rb[id])
                    c[id = nxt] = col;
                else
                {
                    for( ; i <= 2 * n && a[i].o2 < 0; i++);
                    i--;
                    if(i != 2 * n)
                        c[id = nxt = a[i + 1].o2] = col;
                }
            }
            continue;
        }
        if(rb[a[i].o2] > rb[nxt])
            nxt = a[i].o2;
    }
    printf("3\n");
    for(int i = 1; i <= n; i++)
        printf("%c%c", "312"[c[i]], " \n"[i == n]);
}

void oC()
{
    for(int i = 0; i <= 2 * n + 3; i++)
        c[i] = lb[i] = rb[i] = a[i].o1 = a[i].o2 = 0;
}

void oE()
{
    ;
}

int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    oE();
    int T = read();
    while(T--)
        oM(), oC();
    return 0;
}