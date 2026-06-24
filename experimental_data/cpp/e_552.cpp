// whats 1000 minus 7 ?
#include <bits/stdc++.h>
using namespace std;
inline int in(){int32_t x ; scanf("%d",&x) ; return x ; }
inline string get(){char ch[1000010] ; scanf("%s",ch) ; return ch;}
const int MAX_LG = 22;
#define x first
#define y second
#define int long long
#define endl "\n"
#define mp make_pair
typedef pair<int , int > pii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
const int maxn =  5001 + 100;
const int base = 29;
const int mod = 1e9 + 7;
const int INF = 1e9 + 100;
struct st
{
    int a = 0 , b = 0;
    st(){}
    st(int a , int b) : a(a) , b(b) {}
};
st pref[maxn],suf[maxn];
int oper[maxn];
int num[maxn];
int cur;
int res;
int32_t main()
{
    string s = get();
    num[cur ++] = 1;
    oper[1] = 1;
    for (int i = 0 ; i < s.size() ; i ++)
    {
        if (i % 2 == 1)
            oper[cur] = (s[i] == '*');
        else
            num[cur ++] = (s[i] - '0');
    }
    oper[cur] = 1;
    num[cur] = 1;
    suf[cur] = {0,1};
    pref[0] = {0,1};
    for (int i = 1 ; i <= cur ; i ++)
    {
        if (oper[i])
            pref[i] = {pref[i-1].a,pref[i-1].b*num[i]};
        else
            pref[i] = {pref[i-1].a+pref[i-1].b,num[i]};
    }
    for (int i = cur - 1 ; i >= 0 ; i --)
    {
        if (oper[i + 1])
            suf[i] = {suf[i+1].a,suf[i+1].b*num[i]};
        else
            suf[i] = {suf[i+1].a+suf[i+1].b,num[i]};
    }
    res = max(res,pref[cur].a+pref[cur].b);
    for (int i = 1 ; i <= cur ; i ++)
    {
        if (!oper[i]) continue;
        st foo;
        foo.b = num[i];
        for (int j = i + 1 ; j <= cur ; j ++)
        {
            if (oper[j])
                res = max(res,(foo.a+foo.b)*suf[j].b*pref[i-1].b+pref[i-1].a+suf[j].a);
            if (oper[j])
                foo.b *= num[j];
            else foo.a += foo.b , foo.b = num[j];
        }
    }
    cout << res << endl;
}