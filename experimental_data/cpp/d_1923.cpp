/*
# include <iostream>
# include <algorithm>
# define endl '\n';
using namespace std;
const int N = 300010;
typedef long long LL;
LL f[N];


void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> f[i];
	for (int i = 1; i <= n; i ++)
	{
		bool ok = true, okl = true, okr = true;
		int k = 1;
		LL left = f[i - 1], right = f[i + 1];
		if(left > f[i] || right > f[i])
			{
				cout << k <<  ' ';
				ok = false;
			}
		if(ok)
		for (int l = i - 2, r = i + 2; l >= 0 || r <= n; l --, r ++)
		{
			k ++;
			if(f[l] > f[l + 1] && okl) left += f[l];
			else okl = false;
			if(f[r] > f[r - 1] && okr) right += f[r];
			else okr = false;
			if(left > f[i] || right > f[i])
			{
				cout << k <<  ' ';
				ok = false;
				break;
			}
		}
		if(ok) cout << "-1" << ' ';
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t --)
		solve();

	return 0;
}
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> ans(n, n);
    for (int z = 0; z < 2; ++z) {
      vector<long long> s(n + 1);
      for (int i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];
      vector<int> p(n, -1);
      for (int i = 1; i < n; ++i) {
        int j = (z ? n - i - 1 : i);
        int l = 1, r = i;
        while (l <= r) {
          int m = (l + r) / 2;
          if (s[i] - s[i - m] > a[i] && p[i - 1] >= i - m) {
            ans[j] = min(ans[j], m);
            r = m - 1;
          } else {
            l = m + 1;
          }
        }
        if (a[i - 1] > a[i]) ans[j] = 1;
        p[i] = (a[i] == a[i - 1] ? p[i - 1] : i - 1);
      }
      reverse(a.begin(), a.end());
    }
    for (int i = 0; i < n; ++i)
      cout << (ans[i] == n ? -1 : ans[i]) << ' ';
    cout << '\n';
  }
}