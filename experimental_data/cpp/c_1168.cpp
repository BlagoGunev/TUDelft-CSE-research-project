#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

inline char nc() {
    static char buf[300000],*p1,*p2;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,300000,stdin),p1==p2)?EOF:*p1++;
}
int rd() {
    int x=0; char ch=nc();
    while(ch<'0'||ch>'9') ch=nc();
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=nc();
    return x;
}

typedef long long ll;

const int MAX_N = 3e5 + 15, MAX_K = 20, inf = 1e9 + 7;
int n, q;
int Arr[MAX_N];
int dp[MAX_N][MAX_K];
int last[MAX_K];

int main() {
	fill(last, last + MAX_K, -inf);
	for (int i = 0; i < MAX_N; i++)
		fill(dp[i], dp[i] + MAX_K, -inf);

	n = rd();
	q = rd();
	for (int i = 0; i < n; i++)
		Arr[i] = rd();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAX_K; j++)
			if ((Arr[i] >> j) & 1)
				dp[i][j] = last[j];

		for (int j = 0; j < MAX_K; j++)
			if (((Arr[i] >> j) & 1) == 0)
				for (int k = 0; k < MAX_K; k++)
					if (((Arr[i] >> k) & 1) && last[k] != -inf)
						dp[i][j] = max(dp[i][j], dp[last[k]][j]);

		for (int j = 0; j < MAX_K; j++)
			if ((Arr[i] >> j) & 1)
				last[j] = i;
	}

	while (q--) {
		int v, u;
		v = rd();
		u = rd();
		v--, u--;

		bool ok = false;
		for (int j = 0; j < MAX_K; j++)
			if ((Arr[v] >> j) & 1)
				if (v <= dp[u][j]) {
					ok = true;
					break;
				}

		if (ok)
			printf("Shi\n");
		else
			printf("Fou\n");
	}
	return 0;
}