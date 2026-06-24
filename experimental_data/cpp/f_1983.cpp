#include <bits/stdc++.h>
#define N 100005
#define INF 1000000000
using namespace std;
int n, a[N], l[N*32], r[N*32], v[N*32], id;
long long k;
void insert(int v1, int v2, int i=29, int p=1) {
	v[p] = v2;
	if(i == -1) {
		return;
	}
	if(v1&1<<i) {
		if(!l[p]) l[p] = ++id;
		insert(v1,v2,i-1,l[p]);
	} else {
		if(!r[p]) r[p] = ++id;
		insert(v1,v2,i-1,r[p]);
	}
}
int query(int v1, int v2, int i=29, int p=1) {
	if(!p) return 0;
	if(i == -1) return v[p];
	if(v2&1<<i) {
		if(v1&1<<i) {
			return max(v[l[p]], query(v1, v2, i-1, r[p]));
		} else {
			return max(v[r[p]], query(v1, v2, i-1, l[p]));
		}
	} else {
		if(v1&1<<i) {
			return query(v1, v2, i-1, l[p]);
		} else {
			return query(v1, v2, i-1, r[p]);
		}
	}
}
bool works(int val) {
    id = 1;
    for(int i = 0; i <= n*32; i ++) {
    	l[i] = r[i] = v[i] = 0;
    }
    long long ans = 0;
    int maxv = 0;
    for(int i = 2; i <= n; i ++) {
    	insert(a[i-1],i-1);
    	maxv = max(maxv, query(a[i],val));
    	ans += i-maxv-1;
    }
    // cout << 1LL*n*(n-1)/2-ans << "\n";
    return 1LL*n*(n-1)/2-ans >= k;
}
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
    }
    // for(int l = 1; l <= n; l ++) {
    // 	for(int r = l+1; r <= n; r ++) {
    // 		int minv = INF;
    // 		for(int l1 = l; l1 <= r; l1 ++) {
    // 			for(int r1 = l1+1; r1 <= r; r1 ++) {
    // 				minv = min(minv, a[l1]^a[r1]);
    // 			}
    // 		}
    // 		cout << l << " " << r << " " << minv << "\n";
    // 	}
    // }
    // for(int i = 1; i <= 5; i ++) {
    // 	works(i);
    // }
    // cout << works(1) << "\n";
    int l=0, h=(1LL<<30)-1, ans;
    while(l <= h) {
    	int md = l+((h-l)>>1);
    	if(works(md)) {
    		ans = md;
    		h = md-1;
    	} else {
    		l = md+1;
    	}
    }
    cout << ans << "\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int i = 1; i <= t; i ++) {
    	solve();
    }
}