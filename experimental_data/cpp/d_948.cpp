#include<bits/stdc++.h>

using namespace std;
const int maxn = 3e5+100;
int trie[maxn*30][2],cnt[maxn*30],tot = 0;
void insert(int x)
{
    int u = 0;
    for(int i = 30;i >= 0; --i)
    {
        int tp = ((x>>i)&1);
        //cout<<tp<<" ";
        if(!trie[u][tp])trie[u][tp] = ++tot;
        u = trie[u][tp];
        cnt[u]++;
    }
   // for(int i = 0;i < tot; ++i)cout<<cnt[i]<<" ";
//puts("");
}
struct FastIO
{
    static const int S = 10310720;
    int wpos;
    char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar()
    {
        static char buf[S];
        static int len = 0, pos = 0;
        if(pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if(pos == len) return -1;
        return buf[pos ++];
    }
    inline int xuint()
    {
        int c = xchar(), x = 0;
        while(c <= 32) c = xchar();
        for(; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline void wchar(int x)
    {
        if(wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos ++] = x;
    }
    inline void wint(int x)
    {
        if(x < 0) wchar('-'), x = -x;
        char s[24];
        int n = 0;
        while(x || !n) s[n ++] = '0' + x % 10, x /= 10;
        while(n--) wchar(s[n]);
    }
    ~FastIO()
    {
        if(wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;
void find(int x)
{
    int u = 0;
    bitset<391>b;
    for(int i = 30; i >= 0; --i)
    {
        int tp = ((x>>i)&1);
        int v = u;
        if(trie[u][tp]){

            u = trie[u][tp];
            cnt[u]--;
            if(!cnt[u])trie[v][tp] = 0;
        }
        else if(trie[u][tp^1])
        {
            u = trie[u][tp^1];
            cnt[u]--;
            if(!cnt[u])trie[v][tp^1] = 0;
            b[i] = 1;
        }
    }
   io.wint(b.to_ulong());
   io.wchar(' ');
}
int a[maxn];
int main()
{
    int n;
    n = io.xuint();
    for(int i = 1;i <= n; ++i)
    {
        a[i] = io.xuint();
    }
    for(int i = 1;i <= n; ++i)
    {
        int x;
        x = io.xuint();
        insert(x);
    }
    for(int i = 1; i <= n; ++i)
        find(a[i]);

    return 0;
}