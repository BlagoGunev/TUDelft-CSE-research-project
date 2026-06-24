#include <bits/stdc++.h>



#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

#define endl "\n"

#define x first

#define y second



using namespace std;



typedef long long ll;

typedef pair<int,int> PII;



void solve()

{

    int n,x;

    cin >> n >> x;

    vector<int> a(n + 1);

    for(int i = 1; i <= n; i ++) cin >> a[i];

    sort(a.begin() + 1,a.end(),greater<int>());

    ll res = 0,ans = 0;

    for(int i = 1; i <= n; i ++)

        if(a[i] >= x) ans += a[i] - x;

        else

        {

            res = i;

            break;

        }

    if(!res)

    {

        cout << n << endl;

        return;

    }

    for(res; res <= n; res ++)

        if(a[res] + ans >= x) ans -= (x - a[res]);

        else break;

    cout << res - 1 << endl;

    return;

}



int main()

{

    IOS;

    int t = 1;

    cin >> t;



    while(t --)

        solve();



    return 0;

}