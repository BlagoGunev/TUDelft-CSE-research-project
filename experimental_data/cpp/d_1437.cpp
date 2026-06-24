#include<bits/stdc++.h>

#define ll long long
using namespace std;
template<class T>
void read(T& x)
{
	T res = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')f = -1; c = getchar();
	}
	while (isdigit(c)) {
		res = (res << 3) + (res << 1) + c - '0'; c = getchar();
	}
	x = res * f;
}
const ll N = 400000 + 10;
int t, a[N], n;
vector<int>b;
int main()
{
	//ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("182.txt", "r", stdin);
#endif // ONLINE_JUDGE
	read(t);
	while (t--)
	{
		read(n);
		for (int i = 1; i <= n; i++)read(a[i]);
		b.clear();
		int now = 0;
		for (int i = 2; i <= n; i++)
		{
			if (a[i] < a[i - 1])
				b.push_back(now), now = 1;
			else
				now++;
		}
		if (now)b.push_back(now);
		int ans = 0;
		now = 1;
		for (int i = 0; i < b.size();)
		{
			int nnow = 0;
			ans++;
			while ((now--)&&i<b.size())
			{
				nnow += b[i];
				i++;
			}
			now = nnow;
		}
		printf("%d\n", ans);
		
	}
	return 0;
}