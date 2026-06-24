#include<bits/stdc++.h>

#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

#define int long long

using namespace std;

typedef long long LL;

const int maxn = 5e5+10;

const int mod = 1000000007;

const int inf = 0x3f3f3f3f;

int n, m, k;

int a[maxn];

int b[maxn];

int c[maxn];

int vis[maxn];

int lowbit(int x)

{

    return (-x) & x;

}

void update(int x, int y)

{

    while(x <= n)

    {

        a[x] += y;

        x += lowbit(x);

    }



}

int query(int x)

{

    int res = 0;

    while(x)

    {

       res += a[x];

       x -= lowbit(x);

    }

    return res;

}

void solve()

{

    cin >> n >> k;

    for(int i = 1; i <= n; i++)

    {

         cin >> b[i];

         a[i] = 0;

    }

    for(int i = 1; i <= n; i++)

        c[i] = b[i] - b[i-1];

    int ans = 0;

    int num = 0;

    b[n+1] = a[n+1] = 0;

    for(int i = n; i > 0; i--)

    {

        int res = b[i] - (b[i+1] - a[i+1] - num);

       // cout<<res<<' '<< (b[i+1] - a[i+1] - num)<<endl;

        if(res > 0)

        {

           if(i-k >= 0)

           {

               int cnt = (res+k-1)/k;

               a[i-k+1] += cnt;

               num += cnt;

               b[i] += (k-(res % k))%k;

           }

           else

           {

               int cnt = (res+ i-1)/i;

               a[1] += cnt;

               num += cnt;

               b[i] += (i-(res%i))%i;

           }

        }

        else

            b[i] = (b[i+1] - a[i+1] - num);

        num -= a[i];

    }//cout<<endl<<endl;;



    for(int i = 1; i <= n; i++)

     ans += a[i];

    cout<<ans<<endl;

}



signed main()

{

    ios;

    int t = 1; //cin >>t;

    while(t--)

        solve();

    return 0;

}