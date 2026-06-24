#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int res = 0, f = 1; char c = getchar();
	while(!isdigit(c) && c != '-') c = getchar();
	if(c == '-') f = -1, c = getchar();
	while(isdigit(c)) res = (res<<3)+(res<<1)+(c^48), c = getchar();
	return res*f;
}

const int maxn = 1e6+10;
const int mod = 998244353;
int n, k[maxn], vis[maxn];
vector<int> a[maxn];

int inv[maxn];
void pre_inv()
{
	inv[1] = 1;
	for(int i = 2; i <= maxn-5; i++) inv[i] = 1LL*(mod-mod/i)*inv[mod%i]%mod;
	return;
}

int main()
{
	pre_inv();
	n = read();
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		k[i] = read();
		for(int j = 1, u; j <= k[i]; j++) 
		{
			u = read();
			vis[u]++;
			a[i].push_back(u);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int ba = 1LL*inv[n]*inv[k[i]]%mod;
		for(int j = 0; j < k[i]; j++) ans = (ans + 1LL*ba*inv[n]%mod*vis[a[i][j]]%mod)%mod;
	}
	printf("%d\n", ans);
	return 0;
}