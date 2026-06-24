#include <bits/stdc++.h>

#define X first

#define Y second

#define FI(i,a,b) for(int i=(a);i<=(b);i++)

#define FD(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

using LL = long long;

using PII = pair<int,int>;



int m, t, r, B=300;

int w[305], v[610];



int main() {

	scanf("%d%d%d", &m, &t, &r);

	FI(i,1,m) scanf("%d", &w[i]);

	if (t<r) return !printf("-1\n");

	int ans = 0;

	FI(i,1,m) {

		int cnt = 0;

		FI(j,w[i]+B-t, w[i]+B-1) cnt+=v[j];

		if (cnt>=r) continue;

		FD(j,w[i]+B-1,0) {

			if (v[j] || cnt==r) break;

			v[j]=1, ans++, cnt++;

		}

	}

	printf("%d\n", ans);

}