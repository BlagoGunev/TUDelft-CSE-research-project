#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll f[30][30], cnt[30], c[30];
ll ten[30];
const int M=998244353;

int main() {
	ll n;
	scanf("%lld", &n);
	for (int i=1, x; i<=n; i++) {
		scanf("%d", &x);
		int y=x,t=0;
		while (y) {
			c[t++]=y%10;
			y/=10;
		}
		for (int j=0;j<t;j++) f[t][j]+=c[j];
		cnt[t]++;
	}
	
	ten[0]=1;
	for (int i=1; i<=22; i++) ten[i]=ten[i-1]*10%M;
	
	ll ans=0;
	for (int i=1; i<=10; i++) if (cnt[i])
	for (int j=1; j<=10; j++) if (cnt[j]) {
		int u=0, v=0, x=0, y;
		for (int k=0; k<i+j; k++) {
			if ((k%2==0||v==j)&&u<i) 
				x=f[i][u++], y=cnt[j];
			else x=f[j][v++], y=cnt[i];
			ans = (ans+ ten[k]*x%M*y%M)%M;			
		}
	}
	printf("%lld\n", ans);
	
	return 0;
}