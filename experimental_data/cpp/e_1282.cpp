#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, a[Maxn], b[Maxn], c[Maxn], deg[Maxn], tmp[Maxn], nxt[Maxn], las[Maxn], ct, cnt;
set <int> Se[Maxn];
queue <int> Qu;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = 0;
		scanf("%d", &n);
		cnt = n;
		for (int i = 1; i <= n; i++)
			nxt[i] = 0;
		for (int i = 1; i <= n - 2; i++)
			scanf("%d%d%d", &a[i], &b[i], &c[i]), deg[a[i]]++, deg[b[i]]++, deg[c[i]]++, Se[a[i]].insert(i), Se[b[i]].insert(i), Se[c[i]].insert(i);
		for (int i = 1; i <= n; i++)
			if (deg[i] == 1) Qu.push(i);
		while (cnt > 2)
		{
			cnt--;
			int u = Qu.front();
			Qu.pop();
			int now = *Se[u].begin();
			tmp[++ct] = u;
			las[u] = now;
			Se[a[now]].erase(now);
			Se[b[now]].erase(now);
			Se[c[now]].erase(now);
			deg[a[now]]--, deg[b[now]]--, deg[c[now]]--;
			if (deg[a[now]] == 1) Qu.push(a[now]);
			if (deg[b[now]] == 1) Qu.push(b[now]);
			if (deg[c[now]] == 1) Qu.push(c[now]);
		}
		while (!Qu.empty()) Qu.pop();
		nxt[a[las[tmp[n - 2]]]] = b[las[tmp[n - 2]]], nxt[b[las[tmp[n - 2]]]] = c[las[tmp[n - 2]]], nxt[c[las[tmp[n - 2]]]] = a[las[tmp[n - 2]]];
		for (int i = n - 3; i >= 1; i--)
		{
			int now = tmp[i];
			if (now == a[las[now]])
			{
				if (nxt[b[las[now]]] == c[las[now]])
				{
					nxt[b[las[now]]] = now;
					nxt[now] = c[las[now]];
				}
				else
				{
					nxt[c[las[now]]] = now;
					nxt[now] = b[las[now]];
				}
			}
			else if (now == b[las[now]])
			{
				if (nxt[a[las[now]]] == c[las[now]])
				{
					nxt[a[las[now]]] = now;
					nxt[now] = c[las[now]];
				}
				else
				{
					nxt[c[las[now]]] = now;
					nxt[now] = a[las[now]];
				}
			}
			else
			{
				if (nxt[b[las[now]]] == a[las[now]])
				{
					nxt[b[las[now]]] = now;
					nxt[now] = a[las[now]];
				}
				else
				{
					nxt[a[las[now]]] = now;
					nxt[now] = b[las[now]];
				}
			}
		}
		int u = 1;
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", u);
			u = nxt[u];
		}
		printf("\n");
		for (int i = 1; i <= n - 2; i++)
			printf("%d ", las[tmp[i]]);
		printf("\n");
	}
	return 0;
}