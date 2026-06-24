#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1<<18;
int a[N];
int n; 
struct node{
    int w, idx;
    bool operator <(const node& o) const{
        return w < o.w;
    }
}b[N];

int c[N];

void add(int x, int val)
{
    for(int i = x; i <= n; i += i&-i)
    c[i] += val;
}

int query(int x)
{
    int rev = 0;
    for(int i = x; i > 0; i -= i&-i)
    rev += c[i];
    return rev;
}

void solve()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        b[i] = {a[i], i};
    }
    sort(b+1, b+n+1);
    int cnt = 1; a[b[1].idx] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(b[i].w > b[i-1].w) cnt++;
        a[b[i].idx] = cnt;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int front = a[i]==1? 0 : query(a[i]-1);
        int end = query(n) - query(a[i]);
        ans += min(front, end);
        add(a[i],1);
    }
    printf("%lld\n",ans);
    for(int i = 1; i <= n; i++)
    {
        add(a[i], -1);
    }
}

int main()
{
    int t; scanf("%d",&t);
    while(t--) solve();
    // system("pause");
}