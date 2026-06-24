#include <bits/stdc++.h>

#define endl '\n'

#define IOS ios::sync_with_stdio(false);

using namespace std;	



typedef long long ll;

const ll MAXN = 2e5 + 10;

ll n, q;

ll sum = 0, pre = -1;

ll a[MAXN];



int main()

{

	IOS; cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i)

    {

        cin >> a[i];

        sum += a[i];

    }

    map<ll, ll> mp;

    while (q--)

    {

        ll t, pos, val;

        cin >> t;

        if (t == 1) //说明是单值修改

        {

            cin >> pos >> val;

            if (pre == -1)

            {

                ll cha = val - a[pos];

                a[pos] = val;

                sum += cha;

                cout << sum << endl;

            }

            else    //说明这个数已经被前面的全部修改修改过了

            {

                if (mp[pos] == 0)

                {

                    mp[pos] = pre;

                    ll cha = val - mp[pos];

                    mp[pos] = val;

                    sum += cha;

                    cout << sum << endl;

                }

                else 

                {

                    ll cha = val - mp[pos];

                    mp[pos] = val;

                    sum += cha;

                    cout << sum << endl;

                }

            }

        }

        else

        {

            cin >> val;

            sum = val * n;

            pre = val;

            cout << sum << endl;

            mp.clear();

        }

    }

	return 0;

}