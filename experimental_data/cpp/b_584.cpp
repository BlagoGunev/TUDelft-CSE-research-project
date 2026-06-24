#include <bits/stdc++.h>



using namespace std;



#define F first

#define S second

#define x dgbfdgtn

#define x1 dgbfdgtnag

#define x2 dgbfdgtnbgn

#define y dgbfdgtnaerghn

#define y1 dgbfdgtnaerghnsauk

#define y2 dgbfdgtnaerghnajuyls



const long long MOD = 1000000007; /// 10^9 + 7



long long n, ans, t;



int main()

{

    //freopen("run.in", "r", stdin);

    //freopen("run.out", "w", stdout);

    ios_base::sync_with_stdio(0);

    cin >> n;

    ans = t = 1;

    for (int i = 0; i < n; ++i)

    {

        ans *= 27;

        t *= 7;

        ans %= MOD;

        t %= MOD;

    }

    ans = (ans + MOD - t) % MOD;

    cout << ans;

    return 0;

}