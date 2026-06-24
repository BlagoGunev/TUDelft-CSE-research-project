#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() 
{
	i64 x;
	cin >> x;
	std::vector<int> ans;
	int l = 0, r = 0;
	auto rec = [&](auto self, i64 x)
	{
		if (x == 1)
		{
			return;
		}
		if (x % 2 == 1)
		{
			self(self, x - 1);
			ans.push_back(--l);
		}
		else
		{
			self(self, x / 2);
			ans.push_back(++r);
		}
	};
	rec(rec, x);
	cout << ans.size() << "\n";
	for (auto& i : ans)
	{
		cout << i << " \n"[i == ans.back()];
	}
} 

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int t = 1;
	cin >> t;
	
	while (t--) 
	{
		solve();
	}
	
	return 0;
}