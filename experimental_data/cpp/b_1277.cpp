#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
typedef long long ll;
int t,n;
struct node{
	int x,y;
	bool operator < (const node &rhs) const {
		if(x == rhs.x) return y < rhs.y;
		else return x < rhs.x;
	}
}b[maxn];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i = 1,x; i <= n; i++) {
			scanf("%d",&x);
			int cnt = 0;
			while(x % 2 == 0) {
				cnt++;
				x /= 2;
			}
			b[i].x = x;
			b[i].y = cnt;
		}	
		sort(b + 1,b + n + 1);
		ll ans = 0;
		for(int i = 2; i <= n; i++) {
			if(b[i].x != b[i - 1].x) {
				ans += b[i - 1].y;
			}
		}
		ans += b[n].y;
		printf("%lld\n",ans);
	}
	return 0;
}