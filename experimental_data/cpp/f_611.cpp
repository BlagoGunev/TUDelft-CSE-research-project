#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>
#include <functional>
#include <cstring>
#include <string>
#include <map>

using namespace std;

char dat[500003];

int main(){
	int n,h,w;
	scanf("%d%d%d",&n,&h,&w);
	scanf("%s",dat);
	int r1 = 0, r2 = 0, c1 = 0, c2 = 0;
	long long ans = 0;
	const int mod = 1000000007;
	int r = 0, c = 0;
	int magic = 0;

	for (int i = 0; i < n; i++) {
		if (dat[i] == 'L') {
			c--;
		} else if (dat[i] == 'R') {
			c++;
		} else if (dat[i] == 'U') {
			r--;
		} else if (dat[i] == 'D') {
			r++;
		}
		if (r < r1) {
			if (h>0 && w>0) {
				ans = (ans+(i+1)*(long long)w) % mod;
				h--;
			}
			r1 = r;
		}
		if (r > r2) {
			if (h>0 && w>0) {
				ans = (ans+(i+1)*(long long)w) % mod;
				h--;
			}
			r2 = r;
		}
		if (c < c1) {
			if (h>0 && w>0) {
				ans = (ans+(i+1)*(long long)h) % mod;
				w--;
			}
			c1 = c;
		}
		if (c > c2) {
			if (h>0 && w>0) {
				ans = (ans+(i+1)*(long long)h) % mod;
				w--;
			}
			c2 = c;
		}
	}
	if (r == 0 && c == 0) {
		if (h>0 && w>0) {
			puts("-1");
			return 0;
		}
	}
	
	int mover = r, movec = c;
	vector<pair<int,int>> expevent; // time and dir
	for (int i = 0; i < n; i++) {
		if (dat[i] == 'L') {
			c--;
		} else if (dat[i] == 'R') {
			c++;
		} else if (dat[i] == 'U') {
			r--;
		} else if (dat[i] == 'D') {
			r++;
		}
		if (r < r1) {
			r1 = r;
			expevent.emplace_back(i+1, 0);
		}
		if (r > r2) {
			r2 = r;
			expevent.emplace_back(i+1, 0);
		}
		if (c < c1) {
			c1 = c;
			expevent.emplace_back(i+1, 1);
		}
		if (c > c2) {
			c2 = c;
			expevent.emplace_back(i+1, 1);
		}
	}
	if (expevent.empty() && (h>0 && w>0)) {
		puts("-1");
		return 0;
	}
	for(long long basetime = n;h > 0 && w > 0; basetime = (basetime + n) % mod) {
		for (auto ev : expevent) {
			if (h > 0 && w > 0) {
				if (ev.second == 0){
					ans = (ans+(basetime + ev.first)%mod*(long long)w) % mod;
					h--;
				} else {
					ans = (ans+(basetime + ev.first)%mod*(long long)h) % mod;
					w--;
				}
			} else break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}