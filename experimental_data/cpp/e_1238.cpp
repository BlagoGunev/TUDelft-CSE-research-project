#include <bits/stdc++.h>

#define F first
#define S second
#define pi pair<int, int>
#define pb push_back

typedef long long ll;

using namespace std;

const int oo = 1e9, maxN = 20;

int dp[(1 << maxN)], f[(1 << maxN)];
int dis[maxN][maxN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int l, n; cin >> l >> n;
	string s; cin >> s;
	for (int i=0; i+1<l; i++) {
		int c1 = s[i] - 'a', c2 = s[i + 1] - 'a';
		if(c1 == c2) continue ;
		dis[c1][c2] ++;
		dis[c2][c1] ++;
	}
	
	for (int mask=1; mask<(1 << n); mask++) {
		int p = 0;
		for (int i=0; i<n; i++)
			if(mask & (1 << i)) {
				p = i;
				break ;
			}
		
		f[mask] = f[mask ^ (1 << p)];
		for (int c=0; c<n; c++)
			if(mask & (1<< c)) f[mask] -= dis[p][c];
			else {
				f[mask] += dis[p][c];
			}

		//cout << p <<" : " << mask << " --> " << f[mask] << endl;
	}

	for (int mask=1; mask<(1 << n); mask++) {
		dp[mask] = oo;

		for (int c=0; c<n; c++) {
			if((mask & (1 << c)) == 0) continue ;

			int nmask = mask ^ (1 << c);
			int value = dp[nmask] + f[nmask];
			
			dp[mask] = min(dp[mask], value);

		}
	}
	cout << dp[(1 << n) - 1] << '\n';
	
}