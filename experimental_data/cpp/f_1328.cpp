// LUOGU_RID: 95269086
#include <bits/stdc++.h>



using namespace std;



#define ll long long



const ll N = 2e5 + 5;

ll n, k, a[N], pre[N], suf[N], ans = LLONG_MAX, cnt[N];



signed main()

{

	ios::sync_with_stdio(false);

	cin >> n >> k;

	for(ll i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + n + 1);

	for(ll i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

	for(ll i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];

	for(ll i = 1; i <= n; i++)

	{

		if(a[i] == a[i - 1])

		{

			cnt[i] = cnt[i - 1] + 1;

		}

		else cnt[i] = 1;

		if(cnt[i] >= k)

		{

			return puts("0") && 0;

		}

	} 

	for(ll i = 1; i <= n; i++)

	{

		if(i >= k)

		{

			ans = min(ans, i * a[i] - pre[i] - (i - k));

		}

		if(n - i + 1 >= k)

		{

			ans = min(ans, suf[i] - (n - i + 1) * a[i] - (n - i + 1 - k));

		}

		ans = min(ans, i * a[i] - pre[i] + suf[i] - (n - i + 1) * a[i] - (n - k));

	} 

	cout << ans << endl;

	return 0;

}