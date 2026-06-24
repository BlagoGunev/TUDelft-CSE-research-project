#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")



using namespace std;



//#define int int64_t

#define pii pair<int,int>

#define F first

#define S second



mt19937 gen(chrono::system_clock().now().time_since_epoch().count());



int n;

int a[251000];

pii mn[20][251000];

pii mx[20][251000];

int st[251000];



pii get_min(int l, int r) {

    int x = st[r-l+1];

    return min(mn[x][l], mn[x][r-(1<<x)+1]);

}

pii get_max(int l, int r) {

    int x = st[r-l+1];

    return max(mx[x][l], mx[x][r-(1<<x)+1]);

}



int solve (int l, int r) {

    if (l == r) return 0;

    int p1 = min(get_min(l, r).S,get_max(l, r).S), p2 = max(get_min(l, r).S,get_max(l, r).S);

    return solve(l, p1) + 1 + solve(p2, r);

}



void solve ()

{

    cin >> n;

    for (int i=0;i<n;++i) {

        cin >> a[i];

        mn[0][i] = {a[i], i};

        mx[0][i] = {a[i], i};

    }

    for (int j=1;j<20;++j) {

        for (int i=0;i+(1<<j)<=n;++i) {

            mn[j][i] = min(mn[j-1][i], mn[j-1][i+(1<<(j-1))]);

            mx[j][i] = max(mx[j-1][i], mx[j-1][i+(1<<(j-1))]);

        }

    }

    cout << solve(0, n-1) << '\n';

}



int32_t main ()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    st[1] = 0;

    for (int i=2;i<251000;++i) {

        st[i] = st[i/2] + 1;

    }

    int q = 1;

    cin >> q;

    for (;q;--q) {

        solve();

    }

    return 0;

}