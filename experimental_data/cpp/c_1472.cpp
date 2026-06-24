#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

inline void file () {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
}

inline int read () {
	int ans = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) ans = ans * 10 + ch - '0', ch = getchar();
	return ans;
}

typedef long long ll;
const int N = 200005;
const ll INF = (ll)(1e18);
int n;
int a[N];
ll sum[N];
bool flag[N];

void solve () {
	memset(sum, 0, n + 1 << 3);
	for(int i = 0; i <= n; ++ i) flag[i] = false;
	
	n = read();
	for(int i = 1; i <= n; ++ i) a[i] = read();
	
	ll ans = -INF;
	for(int i = 1; i <= n; ++ i) {
		if(flag[i]) continue;
		
		ll cnt = 0;
		int j = i;
		bool lqy = false;
		while(j <= n) {
			if(flag[j]) {
				cnt += sum[j];
				lqy = true;
				break;
			}
			
			flag[j] = true;
			cnt += (ll)a[j];
			j += a[j];
		} 
		
		ans = max(ans, cnt);
		if(!lqy) continue;
		cnt = 0;
		while(j >= i) {
			cnt += (ll)a[j];
			sum[j] = cnt;
			cnt -= (ll)a[j];
			j -= a[j];
		}
	}
	
	printf("%lld\n", ans);
}

int main () {

	int T;
	T = read();
	while(T -- ) solve();

	return 0;
}